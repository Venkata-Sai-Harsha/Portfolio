package practise;

import java.util.Scanner;

public class e6 {
    class Node {
        int data;
        Node next;
        Node prev;
        Node(int data) {
            this.data = data;
        }
    }
    private Node head = null;
    private Node tail = null;

    public void addnode(int data){
        Node newNode = new Node(data);
        if(head==null){
            head=newNode;
            tail=newNode;
            newNode.next=head;
            newNode.prev=head;
        }
        else{
            tail.next=newNode;
            newNode.prev=tail;
            tail=newNode;
            tail.next=head;
            head.prev=tail;
        }
    }

    public void manipulate(){
        if(head == null){
            return;
        }
        Node slow = head;
        Node fast = head;
        while(fast.next!=head && fast.next.next!=head){
            slow=slow.next;
            fast=fast.next.next;
        }
        
        Node prev=null;
        Node curr=head;
        while(curr!=null){
            Node next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }

        Node p1=slow.next;

        head = slow;
        slow.next = null;
        while(p1!=null){
            Node next1=p1.next;
            p1.next=slow;
            slow=p1;
            p1=next1;
        }
        return;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        e6 list=new e6();
        System.out.print("no.of nodes: ");
        int n=sc.nextInt();
        System.out.print("enter the nodes: ");
        for(int i=0;i<n;i++){
            list.addnode(sc.nextInt());
        }
        list.manipulate();
        Node temp=list.head;
        while(temp!=null){
            System.out.print(temp.data);
            System.out.print(" ");
            temp=temp.next;
        }
        System.out.println();
        sc.close();
    }
}