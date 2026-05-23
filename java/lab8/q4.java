package lab8;

import java.util.Scanner;
class q extends Exception{
    public q(String s) {
        super(s);
    }
}
public class q4 {
    public static void productcheck(int age) throws q
    {
        if(age<100){
            throw new q("this is invalid");
        }
        else{
            System.out.println("this is valid");
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        try{
            productcheck(a);
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}