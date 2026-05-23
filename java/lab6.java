/*import java.util.Scanner;

public class lab6 {

	public static void main(String[] args) {
		System.out.println("Enter limit");
		
		Scanner scan = new Scanner(System.in);
		int size = scan.nextInt();
		int[] myList = new int[size];
		
		System.out.println("Enter the elements");
		for (int i = 0; i < size; i++) {
			myList[i] = scan.nextInt();
		}
		
		System.out.println("Display the array");
		for (int i = 0; i < myList.length; i++)
			System.out.println(myList[i]);

		int j = 0, sum = 0;
		System.out.println("Find the sum");
		for (int num : myList) {
			System.out.println(myList[j]);
			j++;
			sum = sum + num;
		}
		
		scan.close();
		System.out.println("Sum" + sum);
	}

}*/




/*import java.util.Scanner;

public class lab6 {
	
	int[] myList;

	 lab6(int size)
	{
		myList=new int[size];
		Scanner scan = new Scanner(System.in);  
		System.out.println("Enter the elements");
		for (int i=0; i<size; i++)
	      {
	    	  myList[i] = scan.nextInt();
	      }
		scan.close();
	}

	void Display() {
		for (int i = 0; i < myList.length; i++)
			System.out.println(myList[i]);

	}
	
	int OddSum() {
		int os=0;
		for(int i=0;i<myList.length;i++)
		{
			if(myList[i]%2!=0)
			{
				os+=myList[i];
			}
		}
		return os;
	}

    public static void main(String[] args) {

		System.out.println("Enter limit");
		Scanner scan = new Scanner(System.in);
		int size = scan.nextInt();
		lab6 myobj = new lab6(size);
		System.out.println("Displaying Array :");
		myobj.Display();
		System.out.print("Sum of odd numbers : ");
		System.out.println(myobj.OddSum());
		scan.close();

	}

}*/


/*import java.util.Scanner;

public class lab6 {
	int rollno;
	String name;
	int m1,m2,m3;
	
	lab6(int R, String S,int mark1,int mark2,int mark3)
	{
		rollno=R;
		name=S;
		m1=mark1;
		m2=mark2;
		m3=mark3;
	}
	void setData(int R,String S,int mark1,int mark2,int mark3)
	{
		rollno=R;
		name=S;
		mark1=m1;
		mark2=m2;
		mark3=m3;
	}
	void ShowData()
	{
		System.out.print("Roll No = "+rollno + "  " + " Student Name = "+name+" Mark 1 = "+m1+" Mark 2 = "+m2+" Mark 3 = "+m3);
        System.out.println();
	}

    static void sortArray(lab6[] arr){
        lab6 temp;   
           for(int i=0; i<arr.length-i;i++)   
               {     
                   for(int j=0; j<arr.length-i-1;j++)   
                       {   
                            if(arr[j].rollno>arr[j+1].rollno)   
                              {   
                                   temp = arr[j];   
                                   arr[j] = arr[j+1];   
                                   arr[j+1] = temp;   
                              }   
                       }   
               }   
         }   

   
   
   static void Grade(lab6[] arr)
   {
       for(int i=0;i<arr.length;i++)
       {
           int percent=(((arr[i].m1+arr[i].m2+arr[i].m3)*100)/300);
           if(percent>90)
           {
               arr[i].ShowData();
               System.out.println("Grade = S\n");
           }else if(percent>=81 && percent<=90)
           {
               arr[i].ShowData();
               System.out.println("Grade = A plus\n");
           }else if(percent>=71 && percent<=80)
           {
               arr[i].ShowData();
               System.out.println("Grade = A \n");
           }else if(percent>=61 && percent<=70)
           {
               arr[i].ShowData();
               System.out.println("Grade = B plus\n");
           }else if(percent>=51 && percent<=60)
           {
               arr[i].ShowData();
               System.out.println("Grade = B\n");
           }else if(percent>=40 && percent<=50)
           {
               arr[i].ShowData();
               System.out.println("Grade = P\n");
           }
       }
   }

   public static void main(String[] args) {
       

       System.out.println("Enter No of students");
       Scanner in = new Scanner(System.in);
       int size = in.nextInt();
       lab6[] myobj = new lab6[size];

       int R,m1,m2,m3;
       String S;
       for (int i = 0; i < size; i++) {
           System.out.println("Enter the next student details");
           R = in.nextInt();
           S = in.next();
           m1=in.nextInt();
           m2=in.nextInt();
           m3=in.nextInt();
           myobj[i] = new lab6(R,S,m1,m2,m3);

       }
       
       in.close();
       
       System.out.println("\nDisplay Student Details");
       for (int i = 0; i < size; i++) {
           myobj[i].ShowData();
       }
       
       System.out.println("\nAfter sorting : ");
       sortArray(myobj);
       for (int i = 0; i < size; i++) {
           myobj[i].ShowData();
       }
       
       System.out.println("\nAssignning Grades : ");
       Grade(myobj);
       

   }
	
}*/



import java.util.Scanner;

class Array2d
{
    int[][] intArray;
    Array2d(int row,int col)
    {
        intArray = new int[row][col];
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the elements :");
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                intArray[i][j] = scan.nextInt();
            }
        }
        scan.close();
    }
    void display(int row,int col)
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                System.out.print(intArray[i][j] + " ");
            }
            System.out.println();
        }
    }

    void sum_anti_diagonal(int row,int col)
    {
        int sum=0;
        int i=0,j=col-1;
        while(i<row && j>=0)
        {
            sum = sum + intArray[i][j];
            i++;
            j--;
        }
        System.out.println("Sum of anti diagonal elements: "+sum);
    }
}

public class lab6 
{
    public static void main(String[] args) 
    {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter no of rows: ");
        int r = scan.nextInt();
        System.out.print("Enter no of columns: ");
        int c = scan.nextInt();

        Array2d A = new Array2d(r,c);
        System.out.println("Displaying new array: ");
        A.display(r,c);
        System.out.println();
        A.sum_anti_diagonal(r,c);
        scan.close();
    }
}