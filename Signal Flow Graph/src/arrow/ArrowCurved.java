package arrow;

import javafx.scene.shape.*;
import javafx.scene.Group;
import javafx.scene.paint.Color;
import javafx.beans.*;
import javafx.beans.property.DoubleProperty;

public class ArrowCurved extends Group implements ArrowI {

	private CubicCurve cubic = new CubicCurve();
	private static final double arrowLength = 10;
	private static final double arrowWidth = 7;

	public ArrowCurved() {
		this(new CubicCurve(), new Line(), new Line());
		
	}

	private ArrowCurved(CubicCurve cubic, Line arrow1, Line arrow2) {
		super(cubic, arrow1, arrow2);
		arrow1.setStrokeWidth(3);
		arrow2.setStrokeWidth(3);
		this.cubic = cubic;
		// Color color = Color.color(1, 1, 1);
		Color color = Color.RED;
		cubic.setStrokeWidth(1);
		cubic.setFill(null);
		cubic.setStroke(color);
		arrow1.setStroke(color);
		arrow2.setStroke(color);
		InvalidationListener updater = o -> {
			double ex = getEndX();
			double ey = getEndY();
			double sx = getStartX();
			double sy = getStartY();

			arrow1.setEndX(ex);
			arrow1.setEndY(ey);
			arrow2.setEndX(ex);
			arrow2.setEndY(ey);

			if (ex == sx && ey == sy) {
				// arrow parts of length 0
				arrow1.setStartX(ex);
				arrow1.setStartY(ey);
				arrow2.setStartX(ex);
				arrow2.setStartY(ey);
			} else {
				double factor = arrowLength / Math.hypot(sx - ex, sy - ey);
				double factorO = arrowWidth / Math.hypot(sx - ex, sy - ey);

				// part in direction of main cubic
				double dx = (sx - ex) * factor;
				double dy = (sy - ey) * factor;

				// part ortogonal to main cubic
				double ox = (sx - ex) * factorO;
				double oy = (sy - ey) * factorO;
				arrow1.setStartX((ex + dx - oy) - 10);
				arrow1.setStartY((ey + dy + ox));
				arrow2.setStartX((ex + dx + oy));
				arrow2.setStartY((ey + dy - ox));
				arrow1.setRotate(20);
				arrow2.setRotate(120);

			}
		};

		// add updater to properties
		startXProperty().addListener(updater);
		startYProperty().addListener(updater);
		endXProperty().addListener(updater);
		endYProperty().addListener(updater);
		updater.invalidated(null);
	}

	public final void setStartX(double value) {
		cubic.setStartX(value);
	}

	public final double getStartX() {
		return cubic.getStartX();
	}

	public final DoubleProperty startXProperty() {
		return cubic.startXProperty();
	}

	public final void setStartY(double value) {
		cubic.setStartY(value);
	}

	public final double getStartY() {
		return cubic.getStartY();
	}

	public final DoubleProperty startYProperty() {
		return cubic.startYProperty();
	}

	public final void setEndX(double value) {
		cubic.setEndX(value);
	}

	public final double getEndX() {
		return cubic.getEndX();
	}

	public final DoubleProperty endXProperty() {
		return cubic.endXProperty();
	}

	public final void setEndY(double value) {
		cubic.setEndY(value);
	}

	public final double getEndY() {
		return cubic.getEndY();
	}

	public final DoubleProperty endYProperty() {
		return cubic.endYProperty();
	}

	@Override
	public String myType() {
		return "Curve";
	}

}