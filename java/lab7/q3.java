import java.util.Scanner;
public class q3 {
	public static void main(String[] args) {	
		String s1;
		Scanner sc=new Scanner(System.in);
		System.out.print("enter string : ");
		s1=sc.next();
		sc.close();
		StringBuffer s=new StringBuffer(s1);
		StringBuffer s2=new StringBuffer(s);
		s2.reverse();
		if(s2.compareTo(s)==0)
		{
			System.out.println("TRUE");
		}else {
			System.out.println("FALSE");
		}
	}
}