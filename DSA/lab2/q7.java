package lab2;

import java.util.Scanner;
public class q7 {
    class node {
        int data;
        node next;
        node(int data){
          this.data=data;
        }
    }
    public node head=null;
    public  node tail=null;
    public void addnode(int data){
        node n=new node(data);
        if(head==null){
            head=n;
            tail=n;
        }
        else{
            tail.next=n;
            tail=n;
        }
    }
    public void display(){
        if(head==null){
            System.out.println("empty");
        }
        node temp=head;
        while(temp!=null){
            System.out.println(temp.data);
            temp=temp.next;
        }

    }
    public int len(node head){
        node temp=head;
        int count=0;
        while(temp!=null){
           count++;
           temp=temp.next;
        }   
        return count;
    }
    public node add(node head1,node head2){
        int carry=0;
        q7 k=new q7();
        node temp1=head1;
        node temp2=head2;
        int x;
        int y;
        while(temp1!=null || temp2!=null){
           
            x=temp1!=null?temp1.data:0;
            y=temp2!=null?temp2.data:0;
            k.addnode((x+y+carry)%10);
            carry=(x+y)/10;
            if(temp1!=null){
                temp1=temp1.next;
            }
            if(temp2!=null){
                temp2=temp2.next;
            }
        }
        return k.head;
    }
 
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter length of first ll");
        int n=sc.nextInt();
        q7 s=new q7();
        System.out.println("Enter values");
        for(int i=0;i<n;i++){
            int k=sc.nextInt();
            s.addnode(k);
        }
        System.out.println("Enter length of second ll");
        int m=sc.nextInt();
        q7 p= new q7();
        System.out.println("Enter values");
        for(int i=0;i<m;i++){
            int k=sc.nextInt();
            p.addnode(k);
        }
        node temp=s.add(s.head, p.head);
        while(temp!=null){
            System.out.println(temp.data);
            temp=temp.next;
        }
        sc.close();    
    }
}