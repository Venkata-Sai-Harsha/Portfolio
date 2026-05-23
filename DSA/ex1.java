import java.util.*;

public class ex1{
    public String name;
    public long number;
    public String address;
    public ex1(String name, long number,String address){
        this.name = name;
        this.number = number;
        this.address = address;
    }

    public void update(String name, long number,String address){
        this.name = name;
        this.number = number;
        this.address = address;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of entries in the directory: ");
        int n = sc.nextInt();
        ex1[] directory = new ex1[n];
        for(int i=0;i<n;i++)
        {
            System.out.print("Enter the name: ");
            String name = sc.next();
            System.out.print("Enter the number: ");
            String number = sc.next();
            int x = number.length();
            System.out.println(x);
            System.out.print("Enter the address: ");
            String address = sc.next();
            //sc.nextLine();

            if(x == 10){
                directory[i] = new ex1(name,Long.parseLong(number),address);
            }
            else{
                System.out.println("Invalid ph_number");
                i--;
            }
        }
        System.out.println();
        for(int i=0;i<directory.length;i++){
            System.out.println(directory[i].name+"  "+directory[i].number+"  "+directory[i].address);
        }
        System.out.println();

        System.out.println("Enter 1 to search phno \nEnter 2 to add contact \nEnter 3 to delete contact \nEnter 4 to Update \nEnter 5 to Exit");
        boolean bool=true;
        do{
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            switch(choice){
                case 1:{
                    System.out.print("Enter the name to be searched:");
                    String search = sc.next();
                    int a1 = 0;
                    for(int i=0;i<directory.length;i++){
                        if(directory[i].name.equals(search)){
                            System.out.println("The number is "+directory[i].number + " " + "Address: "+directory[i].address);
                            a1 = 1;
                            //break;
                        }
                    }
                    bool = true;
                    if(a1==0){
                        System.out.println("Name not found");
                    }
                    System.out.println();
                    break;
                }
                case 2:{
                    System.out.print("Enter the name to be added: ");
                    String name = sc.next();
                    System.out.print("Enter the number to be added: ");
                    long number = sc.nextLong();
                    int x = String.valueOf(number).length();
                    System.out.print("Enter the address to be added: ");
                    String address = sc.next();
                    //sc.nextLine();

                    if(x == 10){
                        directory = Arrays.copyOf(directory,directory.length+1);
                        directory[directory.length-1] = new ex1(name,number,address);
                        System.out.println("Contact added successfully");
                        System.out.println();
                        for(int j=0;j<directory.length;j++){
                            System.out.println(directory[j].name+"  "+directory[j].number+"  "+directory[j].address);
                        }
                        System.out.println();
                        bool = true;
                    }
                    else{
                        System.out.println("Invalid ph_number");
                    }
                    break;
                }
                case 3:{
                    System.out.print("Enter the name to be deleted: ");
                    String name = sc.next();
                    int a2 = 0;
                    for(int i=0;i<directory.length;i++){
                        if(directory[i].name.equals(name)){
                            directory[i] = directory[directory.length-1];
                            directory = Arrays.copyOf(directory,directory.length-1);
                            System.out.println("Contact deleted successfully");
                            System.out.println();
                            for(int j=0;j<directory.length;j++){
                                System.out.println(directory[j].name+"  "+directory[j].number+"  "+directory[j].address);
                            }
                            // System.out.println();
                            a2 = 1;
                            break;
                        }
                    }
                    if(a2 == 0){
                        System.out.println("Name not found");
                    }
                    System.out.println();
                    break;
                }
                case 4:{
                    System.out.println("Enter the name to be updated: ");
                    String name = sc.next();
                    int a3 = 0;
                    for(int i=0;i<directory.length;i++){
                        if(directory[i].name.equals(name)){
                            System.out.print("Enter the new name: ");
                            String new_name = sc.next();
                            System.out.print("Enter the new number: ");
                            long new_number = sc.nextLong();
                            System.out.print("Enter the new address: ");
                            String new_address = sc.next();
                            //sc.nextLine();

                            directory[i].update(new_name,new_number,new_address);
                            System.out.println("Contact updated successfully");
                            System.out.println();
                            for(int j=0;j<directory.length;j++){
                                System.out.println(directory[j].name+"  "+directory[j].number+"  "+directory[j].address);
                            }
                            // System.out.println();
                            a3 = 1;
                            break;
                        }
                    }
                    if(a3 == 0){
                        System.out.println("Name not found");
                    }
                    System.out.println();
                    break;
                }
                case 5:{
                    bool = false;
                    System.out.println("Exited Successfully");
                    System.out.println();
                    break;
                }
            }
        }while(bool);
        sc.close();
    }
}