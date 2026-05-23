import java.util.Scanner;

public class Sum_of_Digits {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a number: ");
        int s=0;
        int n=sc.nextInt();
        while(n>0){
            int r=n%10;
            s=s+r;
            n=n/10;
        }
        System.out.println("Sum: "+ s);
        sc.close();
    }
}