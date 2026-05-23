import java.util.*;

public class lab1b {
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

    public void isPalindrome() {
        if(head == null || head.next == null) {
            System.out.println("palindrome");
            return;
        }
        Node slow = head;
        Node fast = head;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        Node prev = null;
        Node curr = slow;
        while(curr != null) {
            Node next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        Node p1 = head;
        Node p2 = prev;
        while(p2 != null) {
            if(p1.data != p2.data) {
                System.out.println("not a palindrome");
                return;
            }
            p1 = p1.next;
            p2 = p2.next;
        }
        System.out.println("palindrome");
    }
    
    public static void main(String[] args) {
        lab1b list=new lab1b();
        Scanner sc=new Scanner(System.in);
        System.out.print("enter the number of elements : ");
        int n=sc.nextInt();
        System.out.print("enter the element : ");
        for(int i=0;i<n;i++){
            int d=sc.nextInt();
            list.addNode(d);
        }
        list.display();
        list.isPalindrome();
        sc.close();
    }
}