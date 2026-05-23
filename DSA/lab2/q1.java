package lab2;
import java.util.*;

public class q1 {
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

    public void removeduplicate(int data){
        if(head == null || head.next == null) {
            return;
        }
        Node temp = head;
        while(temp != null) {
            Node temp2 = head;
            while(temp2 != null) {
                if(temp2.data == temp.data && temp2 != temp) {
                    temp2.data = temp2.next.data;
                    temp2.next = temp2.next.next;
                }
                temp2 = temp2.next;
            }
            temp = temp.next;
        }

    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        q1 list=new q1();
        System.out.print("no.of nodes: ");
        int n=sc.nextInt();
        list.display();
        System.out.print("input nodes: ");
        for(int i=0;i<n;i++){
            int x=sc.nextInt();
            list.addNode(x);
        }
        list.display();
        list.removeduplicate(n);
        list.display();
        sc.close();
    }
}