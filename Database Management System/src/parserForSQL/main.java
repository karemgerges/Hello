package parserForSQL;

import java.sql.SQLException;

public class main {

	public static void main(String[] args) throws SQLException {
		// TODO Auto-generated method stub
 Validity parser = new Validity("a","b");
 parser.validOrNot("create database db " );
 parser.validOrNot("use db" );
 parser.validOrNot("create table TablenAme (col1 varchar)" );
 parser.validOrNot("Alter table Tablename drop column col1 " );
 parser.validOrNot("Alter table Tablename drop column col1 " );
	}

}
