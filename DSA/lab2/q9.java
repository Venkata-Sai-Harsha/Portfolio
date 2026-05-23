package lab2;

import java.util.Scanner;
public class q9 {
	class nodee{
		nodee next;
		nodee prev;
		int data;
		nodee(int d){
			data = d;
		}
	}
	nodee head =null;
	nodee tail = null;
	nodee temporary = null;
	public void add(int a) {
		nodee newnode = new nodee(a);
		if(head == null) {
			head = newnode;
		}
		else {
			tail.next = newnode;
			tail.next.prev = temporary;
		}
		temporary = newnode;
		tail = newnode;
	}
	public void display() {
		if(head==null) {
			System.out.println("list is empty");
		}
		else {
			nodee temp = head;
			while(temp!=null) {
				System.out.print(temp.data+" ");
				temp = temp.next;
			}
		}
		System.out.println();
		
	}
	public void del(int c,int d) {
		if(c==1) {
			head = head.next;
			head.prev = null;
			//System.out.println(head.data);
		}
		else {
		nodee t = head;
		for(int i=0;i<c-1;i++) {
			t = t.next;
		}
		if(t.next!=null) {
		t.prev.next = t.next;
		t.next.prev = t.prev;}
		else{
			t.prev.next = null;
			tail = t.prev;
			}
		}
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		q9 list = new q9();
		System.out.print("enter the number of list elements :");
		int b = in.nextInt();
		System.out.println("enter the list elements :");
		for(int i=0;i<b;i++) {
			int a = in.nextInt();
			list.add(a);
		}
	   System.out.print("enter the number of customers :");
	   int c = in.nextInt();
		int d =0;
		nodee temp = list.head;
		int t =0;
		int p =1;
		int f = 1;
		if(c<b) {
		while(d<c) {
			if(t==0) {
				temp = temp.next;
				p++;
				if(temp ==null) {
					t=1;
					temp=list.tail;
					p = b;
					
				}
				
			}
			else {
				temp = temp.prev;
				p--;
				if(temp ==null) {
					t=0;
					temp=list.head;
					p=1;
				}
			}
		f++;
		if(f==4) {
			list.del(p,b);
			if(t==0) {
				p--;
			}
			b--;
			f =0;
			d++;
		}}list.display();}
		else {
			System.out.println("list became empty !!");
		}
		in.close();
	
	}
}