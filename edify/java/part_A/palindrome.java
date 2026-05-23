import java.util.Scanner;
public class palindrome{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a string to check if it is a palindrome:");
        String str=sc.nextLine();
        String reversedStr="";
        for(int i=str.length()-1;i>=0;i--){
            reversedStr=reversedStr+str.charAt(i);
        }
        if(str.equals(reversedStr)){
            System.out.println(str+" is a palindrome.");
        }else{
            System.out.println(str+" is not a palindrome.");
        }
        sc.close();
    }
}