package lab2;
import java.util.Scanner;

public class q6 {
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
    public static Node mergeLists(Node l1, Node l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        Node mergedHead;
        if (l1.data < l2.data) {
            mergedHead = l1;
            mergedHead.next = mergeLists(l1.next, l2);
        } 
        else {
            mergedHead = l2;
            mergedHead.next = mergeLists(l1, l2.next);
        }
        return mergedHead;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        q6 list1=new q6();
        q6 list2=new q6();
        System.out.print("enter the number of nodes in list1: ");
        int n1=sc.nextInt();
        System.out.print("enter the elements: ");
        for(int i=0;i<n1;i++){
            int x=sc.nextInt();
            list1.addNode(x);
        }
        System.out.print("enter the number of nodes in list2: ");
        int n2=sc.nextInt();
        System.out.print("enter the elements: ");
        for(int i=0;i<n2;i++){
            int x=sc.nextInt();
            list2.addNode(x);
        }
        list1.display();
        list2.display();
        Node mergedList=mergeLists(list1.head, list2.head);
        System.out.println("merged list is: ");
        while(mergedList!=null){
            System.out.print(mergedList.data);
            System.out.print(" ");
            mergedList=mergedList.next;
        }
        sc.close();
    }
}
