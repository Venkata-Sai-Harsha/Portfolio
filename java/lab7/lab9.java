import java.sql.*;
import java.util.Scanner;

public class lab9 {
	public static void main(String[] args)
	{
		try {
			Class.forName("org.postgresql.Driver");}
		catch(ClassNotFoundException e) {
			System.out.println("class not found");
		}
		try {
			
	    Scanner in = new Scanner(System.in);
		Connection con = DriverManager.getConnection ( "jdbc:postgresql://localhost:5432/ebookshop", "postgres","Sai@15442");
		  Statement statement = con.createStatement();
		System.out.println("enter 1 for displaying the details");
		System.out.println("enter 2 for Update the price of a given id");
		System.out.println("enter 3 for Search for the books having a price range between min and max range");
		System.out.println("enter 4 for Delete the details of a book where the id is given  ");
		System.out.println("enter 5 for Insert a new book detail");
		System.out.println("enter 6 for  Exit");
		int b = in.nextInt();
		if(b ==1) {
			String sql = "select * from books";
			ResultSet result = statement.executeQuery(sql);
			
			while(result.next()) {
				String id = result.getString("id");
				String title = result.getString("title");
				String author = result.getString("author");
				String price = result.getString("price");
				String qty = result.getString("qty");
				System.out.println(id+"  | "+title+"  | "+author+"  | "+price+"  | "+qty);
			}
		}
		if(b == 2) {
			String sql = "update books set price = 38 where id = 1003";
			int rowseffected = statement.executeUpdate(sql);
			System.out.println("Number of rows effected is :"+rowseffected);
			System.out.println("table after update :");
			String ql = "select * from books";
			ResultSet result = statement.executeQuery(ql);
			while(result.next()) {
				String id = result.getString("id");
				String title = result.getString("title");
				String author = result.getString("author");
				String price = result.getString("price");
				String qty = result.getString("qty");
				System.out.println(id+"  | "+title+"  | "+author+"  | "+price+"  | "+qty);
			}
		}
		if(b == 3) {
			String sql = "select * from books where price >= ? and price <=?";
			PreparedStatement preparedstatement =  con.prepareStatement(sql);
			System.out.print("enter the min price of range:");
			float min = in.nextFloat();
			System.out.print("enter the max price of range:");
			float max = in.nextFloat();
			preparedstatement.setFloat(1,min);
			preparedstatement.setFloat(2,max);
			ResultSet result = preparedstatement.executeQuery();
			while(result.next()) {
				String id = result.getString("id");
				String title = result.getString("title");
				String author = result.getString("author");
				String price = result.getString("price");
				String qty = result.getString("qty");
				System.out.println(id+"  | "+title+"  | "+author+"  | "+price+"  | "+qty);
			}
		}
		if(b == 4) {
			String sql = "delete from books where id = ?";
			PreparedStatement preparedstatement = con.prepareStatement(sql);
			System.out.print("enter the id to be deleted:");
			int a = in.nextInt();
			preparedstatement.setInt(1,a);
			int rowsaffected  = preparedstatement.executeUpdate();
			System.out.println("Number of rowsaffected is: "+rowsaffected);
			ResultSet result = statement.executeQuery("select * from books");
			while(result.next()) {
				String id = result.getString("id");
				String title = result.getString("title");
				String author = result.getString("author");
				String price = result.getString("price");
				String qty = result.getString("qty");
				System.out.println(id+"  | "+title+"  | "+author+"  | "+price+"  | "+qty);
			}
		}
		if( b==5) {
			String sql = "insert into books values(1004,'A Cup of Java','Kumar',44.44,44)";
			int rowseffected = statement.executeUpdate(sql);
			System.out.println("Number of rows effected is :"+rowseffected);
			System.out.println("table after update :");
			String ql = "select * from books";
			ResultSet result = statement.executeQuery(ql);
			while(result.next()) {
				String id = result.getString("id");
				String title = result.getString("title");
				String author = result.getString("author");
				String price = result.getString("price");
				String qty = result.getString("qty");
				System.out.println(id+"  | "+title+"  | "+author+"  | "+price+"  | "+qty);
			}
		}
		if(b== 6) {
			con.close();
			System.out.println("connection is disconnected");
		}
	    }
		catch(Exception e) {
			  System.out.println("error occured");
			  System.out.println(e.getMessage());}
		  }
}

		