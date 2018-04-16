package arrow;

import javafx.beans.property.DoubleProperty;

public interface ArrowI {
	public void setStartX(double value);

	public double getStartX();

	public DoubleProperty startXProperty();

	public void setStartY(double value);

	public double getStartY();

	public DoubleProperty startYProperty();

	public void setEndX(double value);

	public double getEndX();

	public DoubleProperty endXProperty();

	public void setEndY(double value);

	public double getEndY();

	public DoubleProperty endYProperty();

	public String myType();
}
