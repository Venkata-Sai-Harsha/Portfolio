import java.util.*;
public class ex2{
	public static void main(String[] args){
		int n;
		Scanner sc=new Scanner(System.in);
        System.out.print("enter the size of array: ");
		n=sc.nextInt();
		int[] arr= new int[n];
        System.out.print("enter the elements of array: ");
		for(int i=0;i<n;i++){
		      arr[i]=sc.nextInt();
		}
		System.out.print("enter the number of rotations: ");
		int r= sc.nextInt();int k;int e;
		for(int i=0;i<r;i++){
			k=arr[0];e=0;
			for(int j=1;j<n;j++){
				arr[e]=arr[j];
				e=e+1;
			}
			arr[n-1]=k;
		}
		for(int i=0;i<n;i++){
			System.out.print(arr[i]+",");
		}
        sc.close();
	}
}