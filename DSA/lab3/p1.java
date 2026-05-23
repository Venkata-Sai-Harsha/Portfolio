//package lab3;

import java.util.*;

public class p1 {
    class Node{
        int data;
        Node next;
        public Node(int data){
            this.data=data;
            this.next=null;
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
        }
        else{
            tail.next=newNode;
            tail=newNode;
            tail.next=head;
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

    public void insertFirst(int data){
        Node temp=head;
        Node newNode=new Node(data);
        head=newNode;
        newNode.next=temp;
        tail.next=head;
    }

    public void insertLast(int data){
        Node temp=head;
        Node newNode=new Node(data);
        while(temp.next!=head){
            temp=temp.next;
        }
        temp.next=newNode;
        newNode.next=head;
        tail=newNode;
    }

    public void insertmiddle(int data,int pos){
        Node temp=head;
        Node newNode=new Node(data);
        for(int i=0;i<pos-1;i++){
            temp=temp.next;
        }
        // newNode.next=temp.next;
        // temp.next=newNode;
        Node h=temp.next;
        temp.next=newNode;
        newNode.next=h;
    }

    public void deletenode(int key){
        Node temp=head;
        Node prev=null;
        if(temp.data==key){
            head=temp.next;
            tail.next=head;
            return;
        }
        while(temp.next!=head){
            if(temp.data==key){
                break;
            }
            prev=temp;
            temp=temp.next;
        }
        if(temp.data==key){
            prev.next=temp.next;
        }
        else{
            System.out.println("not found");
        }
    }

    public void deletemiddle_node(int pos){
        Node temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp.next;
        }
        Node h=temp.next;
        temp.next=h.next;
        h.next=null;
    }

    public void search(int data){
        Node t=head;
        int i=0;
        while(t!=null){
            if(t.data==data){
                System.out.println("data found at index "+i);
                break;
            }
            t=t.next;
            i++;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        p1 list=new p1();
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
            System.out.println("Enter 1 to insert at first \nEnter 2 to insert at last \nEnter 3 to insert at middle \nEnter 4 to delete node \nEnter 5 to delete middle node \nEnter 6 to search \nEnter 7 to exit");
            int y=sc.nextInt();
            if(y==1){
                System.out.print("input data: ");
                int d=sc.nextInt();
                list.insertFirst(d);
                list.display();
            }
            if(y==2){
                System.out.print("input data: ");
                int d=sc.nextInt();
                list.insertLast(d);
                list.display();
            }
            if(y==3){
                System.out.print("input data: ");
                int d=sc.nextInt();
                System.out.print("input position: ");
                int p=sc.nextInt();
                list.insertmiddle(d,p);
                list.display();
            }
            if(y==4){
                System.out.print("input data: ");
                int d=sc.nextInt();
                list.deletenode(d);
                list.display();
            }
            if(y==5){
                System.out.print("input position: ");
                int p=sc.nextInt();
                list.deletemiddle_node(p);
                list.display();
            }
            if(y==6){
                System.out.print("input data: ");
                int d=sc.nextInt();
                list.search(d);
            }
            if(y==7){
                break;
            }
            
        }
        sc.close();
    }
}