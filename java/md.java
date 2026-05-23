/*import java.util.Scanner;

public class md{

  public static void main(String[] args) {
    // Create a Scanner object for user input
    Scanner input = new Scanner(System.in);

    int selection;

    do {
        // Display menu options
        System.out.println("Menu:");
        System.out.println("1. Option 1");
        System.out.println("2. Option 2");
        System.out.println("3. Exit");

        // Get user selection
        System.out.print("Enter your selection: ");
        selection = input.nextInt();

        // Perform action based on selection
        switch (selection) {
            case 1:
                System.out.println("You selected option 1.");
                break;
            case 2:
                System.out.println("You selected option 2.");
                break;
            case 3:
                System.out.println("Exiting program.");
                break;
            default:
                System.out.println("Invalid selection. Please try again.");
                break;
        }
    }while(selection != 3);
  }
}*/


class hi extends Thread{
    public void run(){
        for(int i=0;i<5;i++){
            System.out.println("hi");
            try{Thread.sleep(500);}catch(Exception e){}
        }
    }
}
class hello extends Thread{
    public void run(){
        for(int i=0;i<5;i++){
            System.out.println("hello");
            try{Thread.sleep(500);}catch(Exception e){}
        }
    }
}
public class md {
    public static void main(String[] args) {
        hi obj1=new hi();
        hello obj2=new hello();
        obj1.start();
        try{Thread.sleep(10);}catch(Exception e){}
        obj2.start();
    }
}
