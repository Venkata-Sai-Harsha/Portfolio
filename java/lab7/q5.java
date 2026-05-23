import java.util.Scanner;
public class q5 {
	public static void main(String[] args) {
		String s1;
		Scanner sc=new Scanner(System.in);
		System.out.print("enter the string: ");
		s1=sc.next();
		sc.close();
		String s2="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		int count=0;
		for(int i=0;i<s1.length();i++)
		{
			if(s2.contains(s1.substring(i,i+1))==true)
			{
				count++;
			}
		}
		if(count>=26)
		{
			System.out.println("YES");
		}
		else{
			System.out.println("NO");
		}
	}
}