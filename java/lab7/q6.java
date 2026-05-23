import java.util.Scanner;
public class q6 {
	public static void main(String[] args) {
		String s;
		System.out.print("enter the string: ");
		Scanner sc=new Scanner(System.in);
		s=sc.next();
		StringBuffer s2=new StringBuffer(s);
		int[] U;
		U=new int[s2.length()];
		U[0]=s2.charAt(0)-96;
		for(int i=0;i<s2.length()-1;i++)
		{
			char ch1=s2.charAt(i);
			char ch2=s2.charAt(i+1);
			
			if(ch1==ch2)
			{
				U[i+1]=U[i]+ch2-96;
			}else {
				U[i+1]=ch2-96;
			}
		}
		System.out.print("ENTER n: ");
		int n=sc.nextInt();
		int[] X=new int[n];
		for(int i=0;i<n;i++)
		{	
			System.out.print("enter X[i]: ");
			X[i]=sc.nextInt();
		}
		sc.close();
		for(int i=0;i<n;i++)
		{
			int y=X[i];
			String ans="NO";
			for(int j=0;j<U.length;j++)
			{
				if(U[j]==y)
				{
					ans="YES";
					break;
				}
			}
			System.out.println(ans);
		}
	}
}