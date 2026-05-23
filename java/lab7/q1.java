import java.util.Scanner;
public class q1 {
    public static void main(String[] args) {
        String s,s1;
        char ch;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter s1: ");
        s1=sc.next();
        System.out.print("Enter s: ");
        s=sc.next();
        System.out.print("Enter ch: ");
        ch=sc.next().charAt(0);
        sc.close();
        System.out.println();
        System.out.println("s1: "+s1);
        System.out.println("s: "+s);
        System.out.println(("ch: "+ch));
        System.out.println(("s present in s1? "+s1.contains(s)));
        System.out.println(("is ch in s1?"));

        int x=s1.indexOf((ch));
        if(x!=(-1)){
            System.out.println("Position: "+x);
        }
        else{
            System.out.println("No");
        }
    }
}
