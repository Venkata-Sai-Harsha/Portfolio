import java.math.*;
import java.io.*;
import java.util.*;

public class q4 {
    public static void towerofHanoi(int n, char from, char to, char aux){
        if(n == 1){
            System.out.println("Move disk 1 from "+from+" to "+to);
            return;
        }
        towerofHanoi(n-1, from, aux, to);
        System.out.println("Move disk "+n+" from "+from+" to "+to);
        towerofHanoi(n-1, aux, to, from);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of disks: ");
        int n = sc.nextInt();
        towerofHanoi(n, 'A', 'C', 'B');
        sc.close();
    }
}
