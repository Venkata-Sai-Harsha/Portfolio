package lab2;
import java.util.*;

public class q2 {
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

    public void kthelement(int data){
        Node temp=head;
        for(int i=0;i<data;i++){
            temp=temp.next;
        }
        System.out.println(temp.data);
        System.out.println(tail.data);
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        q2 list=new q2();
        System.out.print("no.of nodes: ");
        int n=sc.nextInt();
        list.display();
        System.out.print("input nodes: ");
        for(int i=0;i<n;i++){
            int x=sc.nextInt();
            list.addNode(x);
        }
        list.display();
        System.out.print("Enter the position that u want: ");
        int k=sc.nextInt();
        list.kthelement(k);
        sc.close();
    }
}
