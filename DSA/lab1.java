import java.util.*;

public class lab1 {
    Scanner sc=new Scanner(System.in);
	class Node{
		int data;
		Node next;
		Node(int data){
			this.data=data;
		}
	}

	public Node head=null;
	public Node tail=null;
	public void addNode(int data) {
		Node newNode=new Node(data);
		if(head==null) {
			head=newNode;
		}
		else {
			tail.next=newNode;
		}
		tail=newNode;
	}
	public void display() {
		if(head==null) {
			System.out.println("empty list");
			return;
		}
		Node temp=head;
		while(temp!=null) {
			System.out.print(temp.data);
            System.out.print(" ");
			temp=temp.next;
		}
        System.out.println();
	} 

    public void insertFirst(int data){
        Node temp=head;
        Node newNode=new Node(data);
        head=newNode;
        newNode.next=temp;
    }

    public void insertLast(int data){
        Node newNode= new Node(data);
        tail.next=newNode;
    }

    public void insertMiddle(int data){
        System.out.print("insert at index : ");
        int d=sc.nextInt();
        Node temp= head;
        for(int i=0;i<d-1;i++){
            temp=temp.next;
        }
        Node newNode= new Node(data);
        Node h=temp.next;
        newNode.next=h;
        temp.next=newNode;
    }

    public void isEmpty(){
        if(head==null){
            System.out.print("list is empty");
        }
        else{
            System.out.print("list is not empty");
        }
    }

    public void deletefirst(int data){
        Node temp=head;
        head=head.next;
        temp.next=null;
    }

    public void deletelast(int data){
        Node t=head;
        while(t.next!=tail){
            t=t.next;
        }
        t.next=null;
        tail=t;
    }

    public void deletemiddle(int data){
        if(data == 0){
            head = head.next;
        }
        else{
            Node previous = null;
            Node current = head;
            for(int i=0;i<data;i++){
                previous = current;
                current=current.next;
            }
            previous.next=current.next;
        }
    }

    public void deleteNode(int key){
        Node temp = head, prev = null;
        if (temp != null && temp.data == key) {
            head = temp.next;
            return;
        }
        while (temp != null && temp.data != key) {
            prev = temp;
            temp = temp.next;
        }
        if (temp == null)
            return;
        prev.next = temp.next;
    }

    public void sorting(int data) {
        for (int i = 0; i < data; i++) {
            for (Node t = head; t.next != null; t = t.next) {
                Node tt = t.next;
                if (t.data > tt.data) {
                    int temp = t.data;
                    t.data = tt.data;
                    tt.data = temp;
                }
            }
        }
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

    public void reverse(){
        Node prev=null;
        Node current=head;
        Node next=head;
        while(current!=null){
            next=current.next;
            current.next=prev;
            prev=current;
            current=next;
        }
        head=prev;
    }

    public void evenpos(){
        Node t=head;
        int i=1;
        while(t!=null){
            if(i%2==0){
                System.out.print(t.data+" ");
            }
            t=t.next;
            i++;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        lab1 list=new lab1();
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
            System.out.println("Enter 1 for inserting at first, \nEnter 2 for inserting middle, \nEnter 3 for insertion at end, \nEnter 4 for delete first node, \nEnter 5 for delete last node, \nEnter 6 for delete middle node, \nEnter 7 for delete the data, \nEnter 8 for sorting, \nEnter 9 for searching, \nEnter 10 for listisempty or not, \nEnter 11 for reverse, \nEnter 12 for even position values, \nEnter 13 for exit ");
            int y=sc.nextInt();
            if(y==1){
                System.out.print("data of newnode: ");
                int x=sc.nextInt();
                list.insertFirst(x);
                list.display();
            }
            else if(y==2){
                System.out.print("data of newnode: ");
                int x=sc.nextInt();
                list.insertMiddle(x);
                list.display();
            }
            else if(y==3){
                System.out.print("data of newnode: ");
                int x=sc.nextInt();
                list.insertLast(x);
                list.display();
            }
            else if(y==4){
                list.deletefirst(y);
                list.display();
            }
            else if(y==5){
                list.deletelast(y);
                list.display();
            }
            else if(y==6){
                System.out.print("index of node to be deleted: ");
                int x=sc.nextInt();
                list.deletemiddle(x);
                list.display();
            }
            else if(y==7){
                System.out.print("data of node to be deleted: ");
                int x=sc.nextInt();
                list.deleteNode(x);
                list.display();
            }
            else if(y==8){
                list.sorting(y);
                list.display();
            }
            else if(y==9){
                System.out.print("data to be searched: ");
                int x=sc.nextInt();
                list.search(x);
            }
            else if(y==10){
                list.isEmpty();
            }
            else if(y==11){
                list.reverse();
                list.display();
            }
            else if(y==12){
                list.evenpos();
            }
            else if(y==13){
                break;
            }
            else{
                System.out.println("invalid choice");
            }
        }
//        System.out.println("\n\n\n - - - Q2 - - -\n");
//
//        SLinkedList list2 = new SLinkedList();
//        list2.addNode(10);
//        list2.addNode(20);
//        list2.addNode(30);
//        list2.addNode(40);
//        list2.addNode(50);
//        list2.addNode(60);
//
//        list2.display();
//
//        System.out.println("\nAfter deleting the elements in positions 3 and 5 :");
//        list2.deletePosition(3);
//        list2.deletePosition(5);
//        list2.display();
//
//        System.out.println("\nAfter inserting the element 25 using sorted insertion");
//        list2.sortedInsertion(25);
//        list2.display();
//
//        System.out.println("\nAfter deleting the element 10 :");
//        list2.deleteElement(10);
//        list2.display();
//
//        System.out.println("\nChecking if the list is empty : ");
//        list2.isEmpty();
//
//        System.out.println("\nChecking if 50 is last element :");
//        list2.isLastElement(50);
//
//        System.out.println("\nDisplaying all even postitioned values :");
//        list2.evenPositionValues();
        sc.close();
        list.isEmpty();
    }
}