import java.util.Scanner;
import java.util.Arrays; 

public class q71 {
	public static void main(String[] args) {
		
		String s1;
		
		Scanner scan=new Scanner(System.in);
		
		System.out.print("enter string :: ");
		s1=scan.next();
		scan.close();
		
		int size=s1.length();
		
		String s2="";
		
		for(int i=size-1;i>=0;i--)
		{
			char ch=s1.charAt(i);
			s2+=ch;
		}
		
		int as1[]=new int[size-1];
		int as2[]=new int[size-1];
		
		for(int i=0;i<size-1;i++)
		{
			as1[i]=(Math.abs(s1.charAt(i)-s1.charAt(i+1)));
			as2[i]=(Math.abs(s2.charAt(i)-s2.charAt(i+1)));
		}
		
		if(Arrays.equals(as1, as2))
		{
			System.out.println("FUNNY");
		}else {
			System.out.println("NOT FUNNY");
		}
		
	}
}
