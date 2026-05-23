import java.util.Scanner;
public class q2 {
	public static void main(String[] args) {
		String a,b;
		int I;
		Scanner sc=new Scanner(System.in);
		System.out.print("enter a : ");
		a=sc.next();
		System.out.print("enter b : ");
		b=sc.next();
		System.out.print("enter I : ");
		I=sc.nextInt();
		sc.close();
		System.out.println(a.substring(0,I)+b.substring(I));
	}
}