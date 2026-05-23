import java.util.Scanner;
public class amstrong {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a number to check if it is an Armstrong number:");
        int n=sc.nextInt();
        int originalNumber = n;
        int sum = 0;
        while(n>0){
            int r=n%10;
            sum=sum+(r*r*r);
            n=n/10;
        }
        if(originalNumber==sum){
            System.out.println(originalNumber+" is an Armstrong number.");
        }else{
            System.out.println(originalNumber+" is not an Armstrong number.");
        }
        sc.close();
    }
}
