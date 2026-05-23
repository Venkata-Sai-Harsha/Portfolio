import java.util.Scanner;
public class prime {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the lower and upper limit to find prime numbers:");
        int l=sc.nextInt();
        int u=sc.nextInt();
        System.out.println("Prime numbers between "+l+" and "+u+" are:");
        for(int i=l;i<=u;i++){
            boolean isPrime=true;
            if(i<2){
                isPrime=false;
            }else{
                for(int j=2;j<=Math.sqrt(i);j++){
                    if(i%j==0){
                        isPrime=false;
                        break;
                    }
                }
            }
            if(isPrime){
                System.out.print(i+" ");
            }
        }
        sc.close();
    }
}
