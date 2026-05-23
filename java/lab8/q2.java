package lab8;

import java.util.*;
public class q2 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("array size: ");
        int n=sc.nextInt();
        int[] arr = new int[n]; 
        for (int i = 0; i < arr.length; i++) {
            System.out.print("Enter a number: ");
            int num = sc.nextInt();
            arr[i] = num;
        }
        //while(true){
        try {
            System.out.print("Enter an array index: ");
            String input = sc.next();
            int index = Integer.parseInt(input);
            System.out.println("The number at index " + index + " is " + arr[index]);
            //break;
        }catch (NumberFormatException e) {
            System.out.println("Please enter a valid number.");
          } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Index out of bounds. Please enter a valid index.");
          }
        //}
        sc.close();
    }
}