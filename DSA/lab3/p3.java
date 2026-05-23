
import java.util.*;

public class p3 {
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
    public void addNode(int data) {
		Node newNode=new Node(data);
		if(head==null) {
			head=newNode;
            //newNode.next=head;
		}
		else {
			tail.next=newNode;
            //newNode.next=head;
		}
        newNode.next=head;
		tail=newNode;
	}
	public void display() {
		Node temp=head;
        if(head==null) {
            System.out.println("empty list");
            return;
        }
        else {
            do {
                System.out.print(temp.data);
                System.out.print(" ");
                temp=temp.next;
            }while(temp!=head);
            System.out.println();
        }
	}

    public void sort() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }

        Node i = head, j = null;
        int temp;

        for(i=head;i.next!=head;i=i.next){
            for(j=i.next;j!=head;j=j.next){
                if(i.data>j.data){
                    temp=i.data;
                    i.data=j.data;
                    j.data=temp;
                }
            }
        }
    }

    public void sorted_insert(int data){
        Node newNode=new Node(data);
        if(head==null){
            head=newNode;
            newNode.next=head;
        }
        else if(head.data>data){
            newNode.next=head;
            head=newNode;
            tail.next=head;
        }
        else{
            Node temp=head;
            while(temp.next!=head && temp.next.data<data){
                temp=temp.next;
            }
            newNode.next=temp.next;
            temp.next=newNode;
        }
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        p3 obj=new p3();
        System.out.print("enter the number of nodes: ");
        int n=sc.nextInt();
        System.out.print("enter the elements: ");
        for(int i=0;i<n;i++){
            int x=sc.nextInt();
            obj.addNode(x);
        }
        obj.display();
        obj.sort();
        obj.display();
        System.out.print("enter the element to be inserted: ");
        int n1=sc.nextInt();
        obj.sorted_insert(n1);
        obj.display();
        sc.close();
    }
}