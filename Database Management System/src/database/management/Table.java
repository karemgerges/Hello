package database.management;

import java.util.LinkedList;

public class Table {
	private String name;
	private LinkedList<Column> columns = new LinkedList<>();

	public Table(String name) {
		this.name = name;
	}

	public void createColumns(LinkedList<String> columnNames, LinkedList<String> columnType) {
		for (int i = 0; i < columnNames.size(); i++) {
			columns.add(new Column(columnNames.get(i), columnType.get(i)));
		}
	}

	public String getName() {
		return this.name;
	}

	public LinkedList<Column> getColumns() {
		return this.columns;
	}

	public void fillColumns(LinkedList<String> values) {
		for (int i = 0; i < values.size(); i++) {
			if (columns.get(i).getType().validate(values.get(i)) == false) {
				return;
			}
		}
		for (int i = 0; i < values.size(); i++) {
			columns.get(i).insertValue(values.get(i));
		}
	}

	public int searchForColumn(String name) {
		int ind = -1;
		for (int i = 0; i < columns.size(); i++) {
			if (columns.get(i).getName().toLowerCase().equals(name.toLowerCase())) {
				ind = i;
			}
		}
		return ind;
	}

	public void deleteRows(LinkedList<Object> rows) {
		for (int j = rows.size() - 1; j > -1; j--) {
			for (int i = 0; i < columns.size(); i++) {
				columns.get(i).deleteValue((int) rows.get(j));
			}
		}
	}
	
	public LinkedList<LinkedList<String>> selectedData(LinkedList<Object> selectedColumns, LinkedList<Object> SelectedRows) {
		LinkedList<LinkedList<String>> selected = new LinkedList<LinkedList<String>>();
		LinkedList<String> innerLinkedList;
		for (int i = 0; i < selectedColumns.size(); i++) {
			innerLinkedList = new LinkedList<>();
			innerLinkedList.add(columns.get((int) selectedColumns.get(i)).getName());
			innerLinkedList.add(columns.get((int) selectedColumns.get(i)).getTheNameOfType());
			selected.add(innerLinkedList);
		}
		for (int k = 0; k < columns.get(0).getValues().size(); k++) {
			for(int ind=0;ind<SelectedRows.size();ind++){
			if ((int) SelectedRows.get(ind) == k) {
				for (int j = 0; j < selectedColumns.size(); j++) {
					selected.get(j).add(columns.get((int) selectedColumns.get(j)).getValues().get(k));
				}
			}
			}
		}
		return selected;
	}


	public void updateRows(LinkedList<Object> rows, LinkedList<String> values, LinkedList<Object> selectedColumns) {
		for (int j = 0; j < rows.size(); j++) {
			for (int i = 0; i < selectedColumns.size(); i++) {
				columns.get((int) selectedColumns.get(i)).updateValue((int) rows.get(j), values.get(i));
			}
		}
	}
}
