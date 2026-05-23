import java.util.Scanner;
public class q4 {
	public static void main(String[] args) {
		String s1;
		Scanner sc=new Scanner(System.in);
		System.out.print("enter the string: ");
		s1=sc.next();
		String s2="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		StringBuffer sb=new StringBuffer();
		for(int i=0;i<s1.length();i++)
		{
			if(s2.contains(s1.substring(i,i+1))==true)
			{
				sb.append(s1.charAt(i));
			}
		}
		s1=sb.toString();
		System.out.println(s1);
		sc.close();
	}
}