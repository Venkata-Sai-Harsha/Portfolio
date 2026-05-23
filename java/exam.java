import java.util.*;

public class exam {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    System.out.print("Enter size of array: ");
    int size = in.nextInt();
    int[] array = new int[size];

    for (int i = 0; i < size; i++) {
      System.out.print("Enter elements: ");
      array[i] = in.nextInt();
    }

    System.out.print("input array :");
    for (int i : array) {
        System.out.print(i + " ");
    }
    System.out.println();

    modifyArray(array);

    System.out.print("Modified array: ");
    for (int i : array) {
      System.out.print(i + " ");
    }
    System.out.println();

    in.close();
  }

  public static void modifyArray(int[] array) {
    int prevOdd;
    for (int i = 0; i < array.length; i++) {
      if (i % 2 == 0) {
        array[i] = array[i] * array[i];
      } 
      else {
        prevOdd = array[i-1];
        array[i] = array[i] + prevOdd;
      }
    }
  }
}
