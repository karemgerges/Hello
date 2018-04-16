#include "QPixmap"
#include <QtWidgets>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QPrintDialog>
#endif
#endif
#include<QMouseEvent>
#include<QRubberBand>
#include<QPoint>
#include "imageviewer.h"
int rotate_Angle;
bool track = false;
ImageViewer::ImageViewer()
   : imageLabel(new QLabel)
   , scrollArea(new QScrollArea)
   , scaleFactor(0.5)
{
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    scrollArea->setVisible(false);
    setCentralWidget(scrollArea);
    createActions();
    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);
}


bool ImageViewer::loadFile(const QString &fileName)
{
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
    }
    setImage(newImage);
    original = newImage;
    resetImage = newImage;
    setWindowFilePath(fileName);
    const QString message = tr("Opened \"%1\", %2x%3, Depth: %4")
        .arg(QDir::toNativeSeparators(fileName)).arg(image.width()).arg(image.height()).arg(image.depth());
    statusBar()->showMessage(message);
    return true;
}

bool ImageViewer::saveFile(const QString &fileName)
{
    QImageWriter writer(fileName);

    if (!writer.write(image)) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot write %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName)), writer.errorString());
        return false;
    }
    const QString message = tr("Wrote \"%1\"").arg(QDir::toNativeSeparators(fileName));
    statusBar()->showMessage(message);
    return true;
}

static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;

    if (firstDialog) {
        firstDialog = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
        ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
    foreach (const QByteArray &mimeTypeName, supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");
    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("jpg");
}

void ImageViewer::open()
{
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().first())) {}
    rotate_Angle = 0;
    setMouseTracking(false);

}

void ImageViewer::saveAs()
{
    QFileDialog dialog(this, tr("Save File As"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptSave);
    while (dialog.exec() == QDialog::Accepted && !saveFile(dialog.selectedFiles().first())) {}
}

void ImageViewer::setImage(const QImage &newImage)
{
    image = newImage;
    imageLabel->setPixmap(QPixmap::fromImage(image));
    scaleFactor = 1.0;

    scrollArea->setVisible(true);
    fitToWindowAct->setEnabled(true);
    updateActions();

    if (!fitToWindowAct->isChecked())
        imageLabel->adjustSize();
}

void ImageViewer::reset()
{
    original = resetImage;
    setImage(resetImage);
    rotate_Angle  = 0;
}

QRubberBand *rubberBand;
QPoint myPoint;
void ImageViewer::mousePressEvent(QMouseEvent *event)
{
    if(track){
        if(imageLabel->underMouse()){
        myPoint = event->pos();
        rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
        rubberBand->show();
           }
    }
}

void ImageViewer::mouseMoveEvent(QMouseEvent *event)
{
    if(track)
        rubberBand->setGeometry(QRect(myPoint, event->pos()).normalized());
}

void ImageViewer::mouseReleaseEvent(QMouseEvent *event)
{
    if(track){
    QPoint a = mapToGlobal(myPoint);
    QPoint b = event->globalPos();
    a = imageLabel->mapFromGlobal(a);
    b = imageLabel->mapFromGlobal(b);
    rubberBand->hide();
    QPixmap OriginalPix(*imageLabel->pixmap());
    double sx = imageLabel->rect().width();
    double sy = imageLabel->rect().height();
    sx = OriginalPix.width() / sx;
    sy = OriginalPix.height() / sy;
    a.setX(int(a.x() * sx));
    b.setX(int(b.x() * sx));
    a.setY(int(a.y() * sy));
    b.setY(int(b.y() * sy));
    QRect myRect(a,b);
    QPixmap ship(QPixmap::fromImage(image));
    QPixmap cropped = ship.copy(myRect);
    image = cropped.toImage();
    imageLabel->setPixmap(QPixmap::fromImage(image));
    normalSize();
    original = image ;
    rotate_Angle  = 0;
    track = false;
    }
}
void ImageViewer::crop()
{
    track = true;
}

void ImageViewer::rotate_left()
{
    rotate_Angle =  (rotate_Angle - 10)%360;
    QApplication::processEvents();
    QPixmap ship(QPixmap::fromImage(original));
    QPixmap rotate(ship.size());
    QPainter p(&rotate);
    p.setRenderHint(QPainter::Antialiasing);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
    p.translate(rotate.size().width() / 2, rotate.size().height() / 2);
    p.rotate(rotate_Angle);
    p.translate(-rotate.size().width() / 2, -rotate.size().height() / 2);
    p.drawPixmap(0, 0, ship);
    p.end();
    image = rotate.toImage();
   imageLabel->setPixmap(rotate);
}

void ImageViewer::rotate_right()
{
    rotate_Angle = (rotate_Angle + 10)%360;
    QApplication::processEvents();
    QPixmap ship(QPixmap::fromImage(original));
    QPixmap rotate(ship.size());
    QPainter p(&rotate);
        p.setRenderHint(QPainter::Antialiasing);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
    p.translate(rotate.size().width() / 2, rotate.size().height() / 2);
    p.rotate(rotate_Angle);
    p.translate(-rotate.size().width() / 2, -rotate.size().height() / 2);
    p.drawPixmap(0, 0, ship);
    p.end();
    image = rotate.toImage();
     imageLabel->setPixmap(rotate);
}


void ImageViewer::zoomIn()
{
    scaleImage(1.25);
}

void ImageViewer::zoomOut()
{
    scaleImage(0.8);
}

void ImageViewer::normalSize()
{
    imageLabel->adjustSize();
    scaleFactor = 1.0;
}

void ImageViewer::fitToWindow()
{
    bool fitToWindow = fitToWindowAct->isChecked();
    scrollArea->setWidgetResizable(fitToWindow);
    if (!fitToWindow)
        normalSize();
    updateActions();
}


void ImageViewer::createActions()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *openAct = fileMenu->addAction(tr("&Open..."), this, &ImageViewer::open);
    openAct->setShortcut(QKeySequence::Open);

    saveAsAct = fileMenu->addAction(tr("&Save As..."), this, &ImageViewer::saveAs);
    saveAsAct->setEnabled(false);

    fileMenu->addSeparator();

    QAction *exitAct = fileMenu->addAction(tr("&Exit"), this, &QWidget::close);
    exitAct->setShortcut(tr("Ctrl+L"));

    QMenu *rotateMenu = menuBar()->addMenu(tr("&Rotate"));

    rotateLeftAct = rotateMenu->addAction(tr("Rotate LEFT"), this,&ImageViewer::rotate_left);
    rotateLeftAct->setShortcut(tr("Ctrl+A"));
    rotateLeftAct->setEnabled(false);

    rotateRightAct = rotateMenu->addAction(tr("Rotate Right"), this,&ImageViewer::rotate_right);
    rotateRightAct->setShortcut(tr("Ctrl+D"));
    rotateRightAct->setEnabled(false);


    QMenu *viewMenu = menuBar()->addMenu(tr("&View"));

    zoomInAct = viewMenu->addAction(tr("Zoom &In (25%)"), this, &ImageViewer::zoomIn);
    zoomInAct->setShortcut(tr("Ctrl+W"));
    zoomInAct->setEnabled(false);

    zoomOutAct = viewMenu->addAction(tr("Zoom &Out (25%)"), this, &ImageViewer::zoomOut);
    zoomOutAct->setShortcut(tr("Ctrl+S"));
    zoomOutAct->setEnabled(false);

    normalSizeAct = viewMenu->addAction(tr("&Normal Size"), this, &ImageViewer::normalSize);
    normalSizeAct->setEnabled(false);

    viewMenu->addSeparator();

    fitToWindowAct = viewMenu->addAction(tr("&Fit to Window"), this, &ImageViewer::fitToWindow);
    fitToWindowAct->setEnabled(false);
    fitToWindowAct->setCheckable(true);
    fitToWindowAct->setShortcut(tr("Ctrl+F"));

    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));

    resetAct = editMenu->addAction(tr("reset"), this,&ImageViewer::reset);
    resetAct->setShortcut(tr("Ctrl+R"));
    resetAct->setEnabled(false);
    cropAct = editMenu->addAction(tr("Crop"), this,&ImageViewer::crop);
    cropAct->setEnabled(false);
}


void ImageViewer::updateActions()
{
    saveAsAct->setEnabled(!image.isNull());
    rotateLeftAct->setEnabled(!image.isNull());
    rotateRightAct->setEnabled(!image.isNull());
    resetAct->setEnabled(!image.isNull());
    cropAct->setEnabled(!image.isNull());
    zoomInAct->setEnabled(!fitToWindowAct->isChecked());
    zoomOutAct->setEnabled(!fitToWindowAct->isChecked());
    normalSizeAct->setEnabled(!fitToWindowAct->isChecked());
}


void ImageViewer::scaleImage(double factor)
{
    Q_ASSERT(imageLabel->pixmap());
    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

    adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(scrollArea->verticalScrollBar(), factor);

    zoomInAct->setEnabled(scaleFactor < 3.0);
    zoomOutAct->setEnabled(scaleFactor > 0.333);
}

void ImageViewer::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}
