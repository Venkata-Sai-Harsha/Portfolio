package lab8;

import java.util.*;
public class q1 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("array size: ");
        int n=sc.nextInt();
        try {
            int[] arr = new int[n];
         } catch (NegativeArraySizeException e) {
            System.out.println("Error: Negative array size");
         }
        sc.close();
    }
}