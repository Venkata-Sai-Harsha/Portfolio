package lab2;

import java.util.Scanner;

public class q4 {
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

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        q4 list=new q4();
        System.out.print("no.of nodes: ");
        int n=sc.nextInt();
        System.out.print("input nodes: ");
        for(int i=0;i<n;i++){
            int x=sc.nextInt();
            list.addNode(x);
        }
        list.display();
        Node slow=list.head;
        Node fast=list.head;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        System.out.println("middle element is: "+slow.data);
        sc.close();
    }
}
