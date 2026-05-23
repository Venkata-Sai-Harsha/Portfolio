//package lab3;
import java.util.*;

public class p2 {
    Scanner sc=new Scanner(System.in);
    class Node{
        int data;
        Node next;
        Node prev;
        public Node(int data){
            this.data=data;
            this.next=null;
            this.prev=null;
        }
    }
    public Node head=null;
    public Node tail=null;
    public void addNode(int data){
        Node newNode=new Node(data);
        if(head==null){
            head=newNode;
            tail=newNode;
            newNode.next=head;
            newNode.prev=tail;
        }
        else{
            tail.next=newNode;
            newNode.prev=tail;
            tail=newNode;
            tail.next=head;
            head.prev=tail;
        }
    }

    public void display(){
        Node temp=head;
        if(head==null){
            System.out.println("empty list");
            return;
        }
        else{
            do{
                System.out.print(temp.data);
                System.out.print(" ");
                temp=temp.next;
            }while(temp!=head);
            System.out.println();
        }
    }

    public void insertmiddle(int data){
        System.out.print("insert at index : ");
        int d=sc.nextInt();
        Node temp=head;
        for(int i=0;i<d-1;i++){
            temp=temp.next;
        }
        Node newNode=new Node(data);
        Node h=temp.next;
        newNode.next=h;
        newNode.prev=temp;
        temp.next=newNode;
        h.prev=newNode;
    }

    public void deletenode(int data){
        Node temp=head;
        if(head==null){
            System.out.println("empty list");
            return;
        }
        else{
            do{
                if(temp.data==data){
                    if(temp==head){
                        head=head.next;
                        head.prev=tail;
                        tail.next=head;
                        break;
                    }
                    else if(temp==tail){
                        tail=tail.prev;
                        tail.next=head;
                        head.prev=tail;
                        break;
                    }
                    else{
                        temp.prev.next=temp.next;
                        temp.next.prev=temp.prev;
                        break;
                    }
                }
                temp=temp.next;
            }while(temp!=head);
        }
    }

    public void sort(){
        Node temp=head;
        Node index=null;
        if(head==null){
            System.out.println("empty list");
            return;
        }
        else{
            do{
                index=temp.next;
                while(index!=head){
                    if(temp.data>index.data){
                        int k=temp.data;
                        temp.data=index.data;
                        index.data=k;
                    }
                    index=index.next;
                }
                temp=temp.next;
            }while(temp!=head);
        }
    }

    public void reverseFirstKNodes(int k) {
        Node current = head;
        Node next = null;
        Node prev = null;
        int count = 0;
        while (count < k && current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
            count++;
        }
        if (next != null) {
            head.next = current;
            current.prev = head;
        }
        head = prev;
        head.prev = tail;
        tail.next = head;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        p2 list=new p2();
        System.out.print("no.of nodes: ");
        int n=sc.nextInt();
        list.display();
        System.out.print("input nodes: ");
        for(int i=0;i<n;i++){
            int x=sc.nextInt();
            list.addNode(x);
        }
        list.display();
        while(true){
            System.out.println("Enter 1 to insert at middle \nEnter 2 to delete a node \nEnter 3 to sort \nEnter 4 to reverse \nEnter 5 to exit");
            int ch=sc.nextInt();
            if(ch==1){
                System.out.print("enter data: ");
                int data=sc.nextInt();
                list.insertmiddle(data);
                list.display();
            }
            else if(ch==2){
                System.out.print("enter data: ");
                int data=sc.nextInt();
                list.deletenode(data);
                list.display();
            }
            else if(ch==3){
                list.sort();
                list.display();
            }
            else if(ch==4){
                System.out.print("Enter the no.of nodes to reverse: ");
                int k = sc.nextInt();
                list.reverseFirstKNodes(k);
                list.display();
            }
            else if(ch==5){
                break;
            }
        }
        sc.close();
    }
}