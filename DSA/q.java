import java.util.Scanner;

public class q{
    class Node{
        int data;
        Node next;
        Node(int data){
            this.data=data;
        }
    }
    public Node head=null;
    public Node tail=null;
    public void addNode(int data){
        Node newNode=new Node(data);
        if(head==null){
            head=newNode;
        }
        else{
            tail.next=newNode;
        }
        tail=newNode;
    }
    public void display(){
        if(head==null){
            System.out.println("empty list");
            return;
        }
        Node temp=head;
        while(temp!=null){
            System.out.print(temp.data);
            System.out.print(" ");
            temp=temp.next;
        }
        System.out.println();
     
    }
    public void fun1(Node head){
        if(head==null){
            System.out.println("empty list");
            return;
        }
        fun1(head.next);
        System.out.print(head.data);
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        q list=new q();
        System.out.print("enter the number of nodes in list: ");
        int n=sc.nextInt();
        System.out.print("enter the nodes: ");
        for(int i=0;i<n;i++){
            list.addNode(sc.nextInt());
        }
        System.out.println("the list is: ");
        list.display();
        System.out.println("the list in reverse is: ");
        list.fun1(list.head);
        System.out.println();
        sc.close();
    }
}