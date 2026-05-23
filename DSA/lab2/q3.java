package lab2;

import java.util.Scanner;

public class q3 {
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

    public void isloopexists(){
        Node current1 = head,current2 = head.next;
        while(current1!=null){
            while(current2!=null){
                if(current1.next == current2.next){
                    System.out.println("Loop exists");
                    return;
                }
                current2 = current2.next;
            }
            current1 = current1.next;
        }
        System.out.println("Loop does not exist");
    }


    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        q3 obj=new q3();
        System.out.print("no.of nodes: ");
        int n=sc.nextInt();
        System.out.print("input nodes: ");
        for(int i=0;i<n;i++){
            int x=sc.nextInt();
            obj.addNode(x);
        }
        obj.display();
        obj.isloopexists();
        sc.close();
    }
}
