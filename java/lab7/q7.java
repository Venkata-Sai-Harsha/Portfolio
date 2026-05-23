import java.util.*;
public class q7
{
    public static void main(String[] args)
    {
        Scanner oops=new Scanner(System.in);
        String s=oops.nextLine();
        int []ascii =new int[s.length()];
        int []reverse_ascii =new int[s.length()];
        int []ascii_diff =new int[s.length()-1];
        int []reverse_ascii_diff =new int[s.length()-1];
        for(int i=0;i<s.length();i++)
        {
            ascii[i]=s.charAt(i);
        }
        for(int i=s.length()-1, j=0;i>=0;i--,j++)
        {
            reverse_ascii[j]=s.charAt(i);
        }
        for(int i=0;i<s.length()-1;i++)
        {
            ascii_diff[i]=Math.abs(ascii[i]-ascii[i+1]);
        }
        for(int i=0;i<s.length()-1;i++)
        {
            reverse_ascii_diff[i]=Math.abs(reverse_ascii[i]-reverse_ascii[i+1]);
        }
        if(Arrays.equals(ascii_diff, reverse_ascii_diff))
        {
            System.out.println("Funny");
        }
        else
        {
            System.out.println("Not Funny");
        }
    }
}