//package lab3;
import java.util.Scanner;

class sort_merge{
    class Node{
        int data;
        Node next;
        Node prev;
        Node(int data){
            this.data = data;
        }
    }

    public Node head = null;
    public Node tail = null;

    public void addnode(int data){
        Node newnode = new Node(data);
        if(head==null){
            head = newnode;
            
        }
        else{
            tail.next=newnode;
            head.prev = newnode;
        }
        tail = newnode;
        newnode.next = head;
        newnode.prev = tail;
    }

    public void display(){
        Node current = head;
        if(head==null)
            System.out.println("List is empty");
        else{
            while (current.next != head) {
                System.out.print(current.data + " ");
                current = current.next;
            }
            System.out.print(current.data + " ");
            System.out.println();
        }
    }

    public void sorted_merge(sort_merge a, sort_merge b){
        Node current1 = a.head;
        Node current2 = b.head;
        
        while (current1 != a.tail && current2 != b.tail) {
            if (current1.data < current2.data) {
                addnode(current1.data);
                current1 = current1.next;
            } 
            else {
                addnode(current2.data);
                current2 = current2.next;
            }
        }
        // add the remaining nodes from list a
        while (current1 != a.tail) {
            addnode(current1.data);
            current1 = current1.next;
        }
        // add the remaining nodes from list b
        while (current2 != b.tail) {
            addnode(current2.data);
            current2 = current2.next;
        }
        // add the last node (the head of list a)
        addnode(current1.data);
        addnode(current2.data);
    } 
}

public class p4 {
    public static void main(String[] args) {
        sort_merge list1 = new sort_merge();
        sort_merge list2 = new sort_merge();
        sort_merge list3 = new sort_merge();
        Scanner sc = new Scanner(System.in);
        System.out.print("no.of nodes in list 1: ");
        int n = sc.nextInt();
        System.out.print("input nodes: ");
        for (int i = 0; i < n; i++) {
            list1.addnode(sc.nextInt());
        }
        System.out.print("no.of nodes in list 2: ");
        n = sc.nextInt();
        System.out.print("input nodes:");
        for (int i = 0; i < n; i++) {
            list2.addnode(sc.nextInt());
        }
        list3.sorted_merge(list1, list2);
        System.out.println("List 1:");
        list1.display();
        System.out.println("List 2:");
        list2.display();
        System.out.println("Merged List:");
        list3.display();
        sc.close();
    }
}