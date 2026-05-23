import java.util.Scanner;
public class fibinocci {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of terms in the Fibonacci series:");
        int n=sc.nextInt();
        int a=0,b=1,c;
        System.out.print("Fibonacci series: "+a+" "+b+" ");
        for(int i=2;i<n;i++){
            c=a+b;
            System.out.print(c+" ");
            a=b;
            b=c;
        }
        sc.close();
    }
}