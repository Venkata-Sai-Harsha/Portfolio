import java.util.Scanner;

public class static_instance_even{
    public static void s_even(int n){
        if(n%2==0){
            System.out.println("Even number: "+n);
        } else{
            System.out.println("Odd number: "+n);
        }
    }
    public void i_even(int n){
        if(n%2==0){
            System.out.println("Even number: "+n);
        } else{
            System.out.println("Odd number: "+n);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number for static method: ");
        int n1 = sc.nextInt();
        s_even(n1);
        System.out.println("Enter another number for instance method: ");
        int n2=sc.nextInt();
        static_instance_even obj = new static_instance_even();
        obj.i_even(n2);
        sc.close();
    }
}