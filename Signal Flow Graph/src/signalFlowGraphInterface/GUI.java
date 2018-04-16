package signalFlowGraphInterface;

import java.util.ArrayList;

import arrow.Arrow;
import arrow.ArrowCurved;
import arrow.ArrowI;
import javafx.application.Application;
import javafx.geometry.*;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import signalFlowGraph.AnalyzeSFG;
import javafx.scene.control.*;
import javafx.scene.text.*;
import javafx.scene.shape.*;

public class GUI extends Application {

	private AnalyzeSFG sfg;
	private Stage stage;
	private HBox h = new HBox();
	private VBox v = new VBox();
	private VBox v2 = new VBox();
	private Pane nodesViewer = new Pane();
	private boolean oneTimeAdd = false;
	private ArrayList<String> forwardPaths;
	private ArrayList<String> loops;

	public static void main(String[] args) {
		Application.launch(args);
	}

	@Override
	public void start(Stage primaryStage) throws Exception {
		stage = primaryStage;

		GridPane textBoxes = textBoxes();
		BorderPane container = new BorderPane();

		// container.setGridLinesVisible(true);
		if (!oneTimeAdd) {
			h.getChildren().add(textBoxes);
			oneTimeAdd = true;
		}
		// nodesViewer.setStyle("-fx-background-color:grey");
		container.setTop(h);
		h.setAlignment(Pos.CENTER);
		v.setAlignment(Pos.TOP_CENTER);
		v2.setAlignment(Pos.TOP_CENTER);

		container.setRight(v);
		container.setLeft(v2);
		container.setCenter(nodesViewer);
		Scene scene = new Scene(container, 1200, 700);
		primaryStage.setScene(scene);
		primaryStage.setResizable(false);
		primaryStage.setTitle("Signal Flow Graph Solver");
		primaryStage.show();

	}

	private Pane nodesViewer(int numberOfNodes) {
		Pane nodesViewer = new Pane();
		// nodesViewer.setStyle("-fx-background-color:grey");
		Circle circle;
		StackPane stack;
		for (int i = 0; i < numberOfNodes; i++) {
			circle = new Circle();
			circle.setRadius(100 / numberOfNodes);
			// circle.setCenterX(200 * i);
			// circle.setCenterY(200);
			// circle.setLayoutX(100);
			circle.setFill(Color.DEEPSKYBLUE);

			// Text text = new Text((i + 1) + "");
			Text text = new Text(i + "");
			text.setBoundsType(TextBoundsType.VISUAL);
			stack = new StackPane();
			stack.getChildren().addAll(circle, text);
			stack.setLayoutY(250);
			stack.setLayoutX(100 * (i + 1));
			nodesViewer.getChildren().add(stack);
		}
		return nodesViewer;

	}

	private void printMatrix(double[][] mat) {
		for (int i = 0; i < mat.length; i++) {
			for (int j = 0; j < mat.length; j++)
				System.out.print(mat[i][j] + " ");
			System.out.println();
		}
	}

	private int[] getArray(String gainString) {
		gainString = gainString.substring(1, gainString.length()).replace("x", " ");
		String[] arrayString = gainString.split(" ");
		int[] array = new int[arrayString.length];
		for (int i = 0; i < arrayString.length; i++) {
			array[i] = Integer.parseInt(arrayString[i]);
		}
		return array;
	}

	private void addGainsOnArrows(String gain, double x, double y, String type) {
		Text t = new Text(gain);
		t.setFont(Font.font(20));
		if (type.equals("Curved")) {
			t.setX(x - 10 - (int) (500 * Math.random()));
			t.setY(y - 100 - (int) (100 * Math.random()));
		} else {
			t.setX(x - 10);
			t.setY(y - 10);
		}

		nodesViewer.getChildren().add(t);
	}

	private void addingArrows(ArrayList<String> arr) {
		ArrowI arrow;
		int[] indexes;
		double[][] matrix = sfg.getMatrix();
		for (int i = 0; i < arr.size(); i++) {
			indexes = getArray(arr.get(i));
			double startX, endX, startY, endY, txtX;
			String gainOnArrow = new String();
			StackPane from, to;
			Bounds fromBounds, toBounds;
			for (int j = 1; j < indexes.length; j++) {
				from = (StackPane) nodesViewer.getChildren().get(indexes[j - 1]);
				to = (StackPane) nodesViewer.getChildren().get(indexes[j]);
				fromBounds = from.getBoundsInParent();
				toBounds = to.getBoundsInParent();
				startX = fromBounds.getMaxX();
				startY = fromBounds.getMaxY();
				endX = toBounds.getMaxX();
				endY = toBounds.getMaxY();
				txtX = (startX + endX) / 2;
				gainOnArrow = matrix[indexes[j]][indexes[j - 1]] + "";

				if (Math.abs(indexes[j - 1] - indexes[j]) > 1 || indexes[j - 1] - indexes[j] == 1) {
					addGainsOnArrows(gainOnArrow, txtX, startY, "Curved");
					arrow = new ArrowCurved();
				} else {
					addGainsOnArrows(gainOnArrow, txtX, startY, "Arrow");
					arrow = new Arrow();
				}
				if (Math.abs(indexes[j - 1] - indexes[j]) == 0) {
					endX += 20;
					endY += 20;
				}

				arrow.setStartX(startX + 10);
				arrow.setStartY(startY);
				arrow.setEndX(endX - 10);
				arrow.setEndY(endY);

				if (arrow.myType().equals("Arrow"))
					nodesViewer.getChildren().add((Arrow) arrow);
				else
					nodesViewer.getChildren().add((ArrowCurved) arrow);

			}
		}
	}

	private void addLines() {
		nodesViewer = nodesViewer(sfg.getNumberOfNodes());
		addingArrows(this.forwardPaths);
		addingArrows(this.loops);

		try {
			start(stage);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	/**
	 * 
	 * @return
	 */
	private GridPane textBoxes() {
		GridPane textBoxes = new GridPane();
		// textBoxes.setGridLinesVisible(true);
		TextField nodesNumber = new TextField();
		TextField from = new TextField();
		TextField to = new TextField();
		TextField gain = new TextField();
		Button enter = new Button("Enter Values");
		Button enterNodesNumber = new Button("Enter Nodes Number");
		enter.setOnAction(e -> {

			if (nodeNumber(from) == 0) {

				sfg.addFinalNode();
				Label gainLabel = new Label("Overall T.F\n" + sfg.operate());
				gainLabel.setFont(new Font(20));
				forwardPaths = sfg.getForwardPath();
				loops = sfg.getNonTouchingLoopsPath().get(0);
				v.getChildren().addAll(gainLabel, forwardPath(), loopsPaths());
				v2.getChildren().add(deltas());
				// this.printMatrix(sfg.getMatrix());
				addLines();
				try {
					start(stage);
				} catch (Exception e1) {
					e1.printStackTrace();
				}
			} else {
				try {
					this.sfg.inputs(nodeNumber(from), nodeNumber(to), gainValue(gain));

				} catch (Exception x) {
				}
			}

			from.setText("");
			to.setText("");
			gain.setText("");

		});

		enterNodesNumber.setOnAction(e -> {
			v = new VBox();
			v2 = new VBox();
			// oneTimeAdd = false;
			sfg = new AnalyzeSFG();
			sfg.setNumberOfNodes(nodeNumber(nodesNumber));
			try {
				this.nodesViewer = new Pane();
				start(stage);
			} catch (Exception e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}

			sfg.createAdjacencyMatrix();
			nodesNumber.setText("");
			// clear all
		});

		textBoxes.add(from, 0, 1);
		textBoxes.add(to, 1, 1);
		textBoxes.add(gain, 2, 1);
		textBoxes.add(enter, 3, 1);
		textBoxes.add(nodesNumber, 1, 0);
		textBoxes.add(enterNodesNumber, 2, 0);
		return textBoxes;
	}

	/////////////////////////////
	private String concatString(ArrayList<String> arrList, String title) {
		StringBuilder concat = new StringBuilder();
		concat.append(title);
		for (int i = 0; i < arrList.size(); i++)
			concat.append("\n" + arrList.get(i));
		return concat.toString();
	}

	private Label forwardPath() {
		Label label = new Label();
		String forwardPathsString = concatString(sfg.getForwardPath(), "\nFORWARD PATHS");
		label.setText(forwardPathsString);
		Font font = new Font(20);
		label.setFont(font);
		return label;
	}

	private Label loopsPaths() {
		Label label = new Label();
		String loopsPathsString = new String();

		for (int i = 0; i < sfg.getNonTouchingLoopsPath().size(); i++)
			loopsPathsString += concatString(sfg.getNonTouchingLoopsPath().get(i),
					("\n\n" + (i + 1) + " Non Touching Loops"));

		label.setText(loopsPathsString);
		Font font = new Font(20);
		label.setFont(font);
		return label;
	}

	private String concatString(ArrayList<Double> arrList) {
		StringBuilder concat = new StringBuilder();
		for (int i = 0; i < arrList.size(); i++)
			concat.append("\n" + "Delta " + i + "\n" + arrList.get(i));
		return concat.toString();
	}

	private Label deltas() {
		Label label = new Label();
		String loopsPathsString = new String();

		// for (int i = 0; i < sfg.getDeltas().size(); i++)
		loopsPathsString += concatString(sfg.getDeltas());

		label.setText(loopsPathsString);
		Font font = new Font(20);
		label.setFont(font);
		return label;
	}

	private int nodeNumber(TextField field) {
		try {
			return Integer.parseInt(field.getText());
		} catch (NumberFormatException x) {
			return -1;

		}
	}

	private double gainValue(TextField gain) {
		try {
			return Double.parseDouble(gain.getText());
		} catch (NumberFormatException x) {
			return Double.NaN;

		}
	}

}
