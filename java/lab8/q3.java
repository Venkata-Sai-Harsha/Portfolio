package lab8;

public class q3 {
    public static void main(String[] args) {
        String str = null;
        try {
          int length = str.length(); 
        } catch (NullPointerException e) {
          System.out.println("Error: " + e.getMessage());
        } finally {
          System.out.println("The program has finished executing.");
        }
      }
}