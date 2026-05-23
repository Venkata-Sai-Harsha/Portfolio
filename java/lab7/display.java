import java.sql.*;

public class display {
    public static void main( String args[] ) {
       Connection c = null;
       Statement stmt = null;
       try {
          Class.forName("org.postgresql.Driver");
          c = DriverManager.getConnection("jdbc:postgresql://localhost:5432/ebookshop","postgres", "Sai@15442");
          c.setAutoCommit(false);
          System.out.println("Opened database successfully");
 
          stmt = c.createStatement();
          ResultSet rs = stmt.executeQuery( "SELECT * FROM books;" );
          while ( rs.next() ) {
             int id = rs.getInt("id");
             String  title = rs.getString("title");
             String author  = rs.getString("author");
             Float price = rs.getFloat("price");
             int qty = rs.getInt("qty");
             System.out.println( "ID = " + id );
             System.out.println( "TITLE = " + title );
             System.out.println( "AUTHOR = " + author );
             System.out.println( "PRICE = " + price );
             System.out.println( "QUANTITY = " + qty );
             System.out.println();
          }
          rs.close();
          stmt.close();
          c.close();
       } catch ( Exception e ) {
          System.err.println( e.getClass().getName()+": "+ e.getMessage() );
          System.exit(0);
       }
       System.out.println("Operation done successfully");
    }
 }