import java.util.*;
public class sh {
    class Node{
        int data;
        Node next;
        Node prev;
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

    public void reverse(){
        Node prev=null;
        Node current=head;
        Node next=null;
        while(current!=null){
            next=current.next;
            current.next=prev;
            prev=current;
            current=next;
        }
        head=prev;
    }

    public void swapAdjacent(){
        Node temp=head;
        while(temp!=null && temp.next!=null){
            int k=temp.data;
            temp.data=temp.next.data;
            temp.next.data=k;
            temp=temp.next.next;
        }
    }

    public void reverseInGroups(int groupSize) {
        head = reverseInGroupsUtil(head, groupSize);
    }

    private Node reverseInGroupsUtil(Node node, int k) {
        Node current = node;
        Node next = null;
        Node prev = null;
        int count = 0;

        // Reverse the first k nodes of the doubly linked list
        while (current != null && count < k) {
            next = current.next;
            current.next = prev;
            current.prev = next;
            prev = current;
            current = next;
            count++;
        }

        // If there are remaining nodes, recursively reverse them
        if (next != null) {
            node.next = reverseInGroupsUtil(next, k);
            node.next.prev = node;
        }

        return prev;
    }

    //Write an algorithm to swap the values of ith node from the beginning and jth node from the end. In java
    public void swap(int i,int j){
        Node temp=head;
        Node temp1=head;
        int count=0;
        while(temp!=null){
            count++;
            temp=temp.next;
        }
        int k=count-j;
        int l=0;
        while(l<i-1){
            temp1=temp1.next;
            l++;
        }
        Node temp2=head;
        int m=0;
        while(m<k-1){
            temp2=temp2.next;
            m++;
        }
        int n=temp1.data;
        temp1.data=temp2.data;
        temp2.data=n;
    }
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        sh list=new sh();
        System.out.print("no.of nodes: ");
        int n=sc.nextInt();
        System.out.print("enter nodes: ");
        for(int i=0;i<n;i++){
            list.addNode(sc.nextInt());
        }
        list.display();
        // list.reverse();
        // list.display();
        // list.swapAdjacent();
        // list.display();
        // System.out.print("enter nodes to swap: ");
        // int i=sc.nextInt();
        // int j=sc.nextInt();
        // list.swap(i,j);
        
        list.reverseInGroups(n);
        list.display();
    }
}