import java.util.*;

public class exam1 {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.print("Enter name: ");
    String name = in.nextLine();
    String modifiedName = modifyName(name);
    System.out.println("Modified name: " + modifiedName);
    in.close();
  }

  public static String modifyName(String name) {
    String[] parts = name.split(" ");
    String firstName = parts[0];
    String middleInitial = parts[1].substring(0, 1);
    String lastName = parts[2].substring(0, 1);
    return firstName + "." + middleInitial + "." + lastName;
  }
}