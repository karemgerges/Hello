package assembler;
import java.awt.Point;
import java.sql.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class AnalyzeSFG {

	private int[][] adjMatrix;
	private int numberOfNodes;
	private String path = new String();
	private int forwardPathGain = 1;
	private ArrayList<String> loopsPath = new ArrayList<>();
	private ArrayList<String> forwardPath = new ArrayList<>();
	private ArrayList<Integer> forwardGains = new ArrayList<>();
	private ArrayList<Integer> loopsGains = new ArrayList<>();
	private ArrayList<Point> searchLoops = new ArrayList<>();
	private ArrayList<ArrayList<String>> nonTouchingLoopsPath = new ArrayList<>();
	private ArrayList<ArrayList<Integer>> nonTouchingLoopsGains = new ArrayList<>();
	private ArrayList<Integer> nonTouchedLoopsWithPathGains = new ArrayList<>();
	private Scanner scan;

	public static void main(String[] args) {
		AnalyzeSFG g = new AnalyzeSFG();
		g.inputs();
		g.printMatrix();
		g.traverseForwardPath(0);
		g.loops();
		g.nonTouchingLoops();
		g.print();
		// System.out.println("mason value = " + g.masonValue());
	}

	private void makeAllZeros(int[][] matrix) {
		for (int i = 0; i < matrix.length; i++)
			Arrays.fill(matrix[i], 0);
	}

	private void inputs() {
		scan = new Scanner(System.in);
		System.out.print("Enter The Number Of Nodes : ");
		numberOfNodes = scan.nextInt();
		adjMatrix = new int[numberOfNodes][numberOfNodes];
		makeAllZeros(adjMatrix);
		System.out.println("To Get Out From Entering Signal Flow Graph Representation");
		System.out.println("Put From = 0 ");
		while (true) {
			int from, to, gain;
			System.out.print("From : ");
			from = scan.nextInt() - 1;
			if (from < 0) {
				break;
			}
			System.out.print("To : ");
			to = scan.nextInt() - 1;
			System.out.print("gain : ");
			gain = scan.nextInt();
			adjMatrix[to][from] = gain;
		}
		addFinalNode();
	}

	private void printMatrix() {
		for (int i = 0; i < numberOfNodes; i++) {
			for (int j = 0; j < numberOfNodes; j++) {
				System.out.print(adjMatrix[i][j] + " ");
			}
			System.out.println();
		}

	}

	private void print() {
		System.out.println("Forward Paths");
		for (int i = 0; i < this.forwardGains.size(); i++) {
			System.out.println(this.forwardGains.get(i));
			System.out.println(this.forwardPath.get(i));
		}
		System.out.println("\nLoops");
		for (int i = 0; i < this.loopsPath.size(); i++) {
			System.out.println(this.loopsPath.get(i));
			System.out.println(this.loopsGains.get(i));
		}
	}

	private int[][] copyMatrix(int[][] copyTo, int[][] copyFrom) {
		for (int i = 0; i < copyFrom.length; i++)
			for (int j = 0; j < copyFrom.length; j++)
				copyTo[i][j] = copyFrom[i][j];
		return copyTo;
	}

	private int[] getLoopPathArray(String gainString) {
		gainString = gainString.substring(1, gainString.length()).replace("x", " ");
		String[] arrayString = gainString.split(" ");
		int[] array = new int[arrayString.length];
		for (int i = 0; i < arrayString.length; i++) {
			array[i] = Integer.parseInt(arrayString[i]);
		}
		return array;
	}

	private int getSimpleLoopGain(String gainString) {
		int[] array = getLoopPathArray(gainString);
		int column, row;
		int gain = 1;
		for (int i = 1; i < array.length; i++) {
			column = array[i - 1];
			row = array[i];
			gain *= adjMatrix[row][column];
		}
		return gain;
		// x1x2x3x4x1
	}

	private int getSimpleLoopGain(int[] array) {
		int column, row;
		int gain = 1;
		for (int i = 1; i < array.length; i++) {
			column = array[i - 1];
			row = array[i];
			gain *= adjMatrix[row][column];
		}
		return gain;
		// x1x2x3x4x1
	}

	private void addFinalNode() {
		boolean addColumn = false;
		for (int i = 0; i < this.adjMatrix.length; i++)
			if (this.adjMatrix[i][this.numberOfNodes - 1] != 0) {
				addColumn = true;
				break;
			}

		if (addColumn == true) {
			int newDimension = this.numberOfNodes + 1;
			int[][] copy = new int[newDimension][newDimension];
			makeAllZeros(copy);
			copy = copyMatrix(copy, adjMatrix);
			copy[newDimension - 1][newDimension - 2] = 1;
			adjMatrix = copy;
			this.numberOfNodes = newDimension;
		}
	}

	private void loops() {
		// searching for self loops
		for (int i = 0; i < numberOfNodes; i++) {
			if (adjMatrix[i][i] != 0) {
				String selfLoop = "x" + i + "x" + i;
				loopsPath.add(selfLoop);
				loopsGains.add(adjMatrix[i][i]);
			}
		}
		// finding possible loops path
		for (int i = 1; i < numberOfNodes; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (adjMatrix[j][i] != 0) {
					// from i to j (reverse path) j <==== i
					Point x = new Point(j, i);
					searchLoops.add(x);
				}
			}
		}
		// search in the forwardPathes for path from j to i
		// if found j ===> i then the is a loop j => i => j
		for (int i = 0; i < this.forwardPath.size(); i++) {
			String current = this.forwardPath.get(i);
			for (int j = 0; j < this.searchLoops.size(); j++) {
				int x = this.searchLoops.get(j).x;
				String from = "x" + x;
				if (current.contains(from)) {
					int y = this.searchLoops.get(j).y;
					String to = "x" + y;
					if (current.contains(to)) {
						// this is a loop we must calculate the gain and print
						// the loop path
						int start = current.lastIndexOf(from);
						int end;
						if (y < 10)
							end = current.lastIndexOf(to) + 1;
						else
							end = current.lastIndexOf(to) + 2;
						String loop;
						if (x < 10)
							loop = current.substring(start, end + 1) + current.substring(start, start + 2);
						else
							loop = current.substring(start, end + 1) + current.substring(start, start + 3);
						// Check that this loop isn't already taken
						boolean exist = false;
						for (int k = 0; k < this.loopsPath.size(); k++) {
							if (loop.equals(this.loopsPath.get(k))) {
								exist = true;
							}
						}
						if (!exist) {
							loopsPath.add(loop);
							loopsGains.add(getSimpleLoopGain(loop));
						}
					}
				}
			}
		}
	}

	private void nonTouchingLoops() {
		ArrayList<String> pathes = new ArrayList<>();
		ArrayList<Integer> gains = new ArrayList<>();
		// search for the two non-touching loops
		for (int i = 0; i < this.loopsPath.size(); i++) {
			pathes.add(loopsPath.get(i));
			gains.add(loopsGains.get(i));
		}
		this.nonTouchingLoopsPath.add(pathes);
		this.nonTouchingLoopsGains.add(gains);
		pathes = new ArrayList<>();
		gains = new ArrayList<>();
		for (int i = 0; i < this.nonTouchingLoopsPath.get(0).size(); i++) {
			for (int j = i + 1; j < this.nonTouchingLoopsPath.get(0).size(); j++) {
				if (!areTouching(this.nonTouchingLoopsPath.get(0).get(i), this.nonTouchingLoopsPath.get(0).get(j))) {
					String nonTouchingLoop = this.nonTouchingLoopsPath.get(0).get(i)
							+ this.nonTouchingLoopsPath.get(0).get(j);
					int gain = this.nonTouchingLoopsGains.get(0).get(i) * this.nonTouchingLoopsGains.get(0).get(j);
					pathes.add(nonTouchingLoop);
					gains.add(gain);
				}
			}
		}
		if (pathes.size() > 0) {
			this.nonTouchingLoopsPath.add(pathes);
			this.nonTouchingLoopsGains.add(gains);
		}
		// search for more than two non touching loops
		int k = 1;
		while (nonTouchingLoopsPath.size() == k + 1) {
			pathes = new ArrayList<>();
			gains = new ArrayList<>();
			for (int i = 0; i < this.nonTouchingLoopsPath.get(k).size(); i++) {
				for (int j = 0; j < this.nonTouchingLoopsPath.get(k - 1).size(); j++) {
					if (!areTouching(this.nonTouchingLoopsPath.get(k).get(i),
							this.nonTouchingLoopsPath.get(k - 1).get(j))) {
						String nonTouchingLoop = this.nonTouchingLoopsPath.get(k).get(i)
								+ this.nonTouchingLoopsPath.get(k - 1).get(j);
						int gain = this.nonTouchingLoopsGains.get(k).get(i)
								* this.nonTouchingLoopsGains.get(k - 1).get(j);
						if (pathes.size() == 0) {
							pathes.add(nonTouchingLoop);
							gains.add(gain);
						} else {
							boolean equal = false;
							int[] a = getLoopPathArray(nonTouchingLoop);
							for (int m = 0; m < pathes.size(); m++) {
								int[] b = getLoopPathArray(pathes.get(m));
								if (a.length == b.length) {
									Arrays.sort(a);
									Arrays.sort(b);
									for (int z = 0; z < a.length; z++) {
										if (a[i] == b[i]) {
											equal = true;
											break;
										}
									}
								}
							}
							if (!equal) {
								pathes.add(nonTouchingLoop);
								gains.add(gain);
							}
						}
					}
				}
			}
			if (pathes.size() > 0) {
				this.nonTouchingLoopsPath.add(pathes);
				this.nonTouchingLoopsGains.add(gains);
				k++;
			} else {
				k++;
			}
		}
		// printing the nonTouched loops
		if (nonTouchingLoopsPath.size() > 1) {
			System.out.println("nonTouching");
			for (int i = 1; i < this.nonTouchingLoopsPath.size(); i++) {
				for (int j = 0; j < this.nonTouchingLoopsPath.get(i).size(); j++) {
					System.out.println(this.nonTouchingLoopsPath.get(i).get(j));
					System.out.println(this.nonTouchingLoopsGains.get(i).get(j));
				}
			}
		}
	}

	private void nonTouchingWithPathGain() {
		ArrayList<ArrayList<Integer>> nonTouchedLoopsWithPathGain = new ArrayList<>();
		ArrayList<Integer> gains;
		for (int i = 0; i < forwardPath.size(); i++) {
			gains = new ArrayList<>();
			for (int j = 0; j < this.nonTouchingLoopsPath.size(); j++) {
				int sum = 0;
				for (int k = 0; k < this.nonTouchingLoopsPath.get(j).size(); k++) {
					if (!areTouching(forwardPath.get(i), this.nonTouchingLoopsPath.get(j).get(k))) {
						sum += this.nonTouchingLoopsGains.get(j).get(k);
					}
				}
				gains.add(sum);
			}
			nonTouchedLoopsWithPathGain.add(gains);
		}
		for (int i = 0; i < nonTouchedLoopsWithPathGain.size(); i++) {
			int gainSum = 1;
			for (int j = 0; j < nonTouchedLoopsWithPathGain.get(i).size(); j++) {
				if (j % 2 == 0) {
					gainSum -= nonTouchedLoopsWithPathGain.get(i).get(j);
				} else {
					gainSum += nonTouchedLoopsWithPathGain.get(i).get(j);
				}
			}
			this.nonTouchedLoopsWithPathGains.add(gainSum);
		}
	}

	private double numerator() {
		nonTouchingWithPathGain();
		int numerator = 0;
		for (int i = 0; i < forwardPath.size(); i++) {
			numerator += this.forwardGains.get(i) * this.nonTouchedLoopsWithPathGains.get(i);
		}
		return numerator;
	}

	private double denominator() {
		// 1 - (sum gains individual) + (sum gain of two non touching)
		ArrayList<Integer> sumGains = new ArrayList<>();
		for (int i = 0; i < this.nonTouchingLoopsPath.size(); i++) {
			int sum = 0;
			for (int j = 0; j < this.nonTouchingLoopsPath.get(i).size(); j++) {
				sum += this.nonTouchingLoopsGains.get(i).get(j);
			}
			sumGains.add(sum);
		}
		int denominator = 1;
		for (int k = 0; k < sumGains.size(); k++) {
			if (k % 2 == 0) {
				denominator -= sumGains.get(k);
			} else {
				denominator += sumGains.get(k);
			}
		}
		return denominator;
	}

	private double masonValue() {
		return numerator() / denominator();
	}

	private boolean areTouching(String loopPath1, String loopPath2) {
		return compareTwoLoops(getLoopPathArray(loopPath1), getLoopPathArray(loopPath2));
	}

	private boolean compareTwoLoops(int[] loopPath1, int[] loopPath2) {
		for (int i = 0; i < loopPath1.length; i++)
			for (int j = 0; j < loopPath2.length; j++)
				if (loopPath1[i] == loopPath2[j])
					return true;
		return false;
	}

	private void traverseForwardPath(int columnIndex) {

		if (isLastNode(columnIndex)) {
			addToForwardPath(columnIndex, 1);
			forwardPath.add(path);
			forwardGains.add(forwardPathGain);
			path = path.replace("x" + columnIndex, "");
			return;
		}

		int rowIndex = -1;
		rowIndex = getNextNode(rowIndex + 1, columnIndex);
		while (rowIndex != -1) {
			if (rowIndex <= columnIndex) {
				rowIndex = getNextNode(rowIndex + 1, columnIndex);
				continue;
			}
			addToForwardPath(columnIndex, adjMatrix[rowIndex][columnIndex]);
			traverseForwardPath(rowIndex);
			removeFromForwardPath(columnIndex, adjMatrix[rowIndex][columnIndex]);
			rowIndex = getNextNode(rowIndex + 1, columnIndex);
		}
	}

	private void removeFromForwardPath(int currentNode, int gain) {
		String toBeRemoved = "x" + currentNode;
		if (path.contains(toBeRemoved))
			path = path.replace(toBeRemoved, "");
		forwardPathGain /= gain;

	}

	private void addToForwardPath(int currentNode, int gain) {
		path += "x" + currentNode;
		forwardPathGain *= gain;
	}

	private int getNextNode(int rowIndex, int columnIndex) {
		for (; rowIndex < this.numberOfNodes; rowIndex++)
			if (adjMatrix[rowIndex][columnIndex] != 0)
				return rowIndex;
		return -1;
	}

	private boolean isLastNode(int columnIndex) {
		for (int i = 0; i < this.numberOfNodes; i++)
			if (adjMatrix[i][columnIndex] != 0)
				return false;
		return true;
	}

}