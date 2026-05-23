//package lab3;

import java.util.Scanner;
public class p5 {
    class node{
        int data;
        node prev;
        node next;
        node(int data){
           this.data=data;
           prev=null;
           next=null;
        }
    }
    public node head=null;
    public node tail=null;
    public void addnode(int data){
     node n=new node(data);
     if(head==null){
          head=n;
     }
     else{
        tail.next=n;
        n.prev=tail;
     }
     tail=n;
    }
    public void display(){
        if(head==null){
            System.out.println("empty");
            return;
        }
        node temp=head;
        while(temp!=null){
            System.out.print(temp.data);
            temp=temp.next;
        }
    }
   public void sumpair(int k){
    node temp1=head;
    node temp2=null;
    while(temp1!=null){
        temp2=temp1.next;
        while(temp2!=null){
               if(temp1.data+temp2.data==k){
                System.out.println("("+temp1.data+","+temp2.data+")");
               }
               temp2=temp2.next;
        }
        temp1=temp1.next;
    }
   }
    public static void main(String[] args) {
        p5 s= new p5();
        Scanner sc= new Scanner(System.in);
        System.out.print("no.of nodes: ");
        int n=sc.nextInt();
        int k;
        System.out.print("input nodes: ");
        for(int i=0;i<n;i++){
             k=sc.nextInt();
            s.addnode(k);
        }
        System.out.print("Enter num: ");
        k=sc.nextInt();
        s.sumpair(k);
        sc.close();
    }
}