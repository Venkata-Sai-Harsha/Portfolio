package lab2;

public class q8 {
    class node{
        String name;
       String  num;
        node next;
        node(String name,String num){
            this.name=name;
            this.num=num;
            next=null;
        }
    }
    public node head=null;
    public node tail=null;
    public void add(String name,String num){
        node n=new node(name,num);
        if(head==null){
            head=tail=n;
        }
        else{
            if(head.name.compareToIgnoreCase(name)>=0){
                n.next=head;
                head=n;
                return;
            }
            node temp=head;
            while(temp.next!=null && temp.next.name.compareToIgnoreCase(name)<0){
                temp=temp.next;
            }
            n.next=temp.next;
            temp.next=n;
            if(temp.next==null){
                tail=n;
            }
        }
    }
    public void  delete(String name){
        if(head==null){
            System.out.println("empty");
            return;
        }
        if(head.name.compareToIgnoreCase(name)==0){
            head=head.next;
            System.out.println(name +" is deleted");
        }
        node temp=head;
        while(temp.next!=null && temp.next.name.compareToIgnoreCase(name)!=0){
         temp=temp.next;  
        }
        if(temp.next==null){
            System.out.println(name+" is not found");
            return;
        }
        if(temp.next.next==null){
            temp.next=null;
            tail=temp;
            System.out.println(name+" is deleted");
            return;
        }
        temp.next=temp.next.next;
        System.out.println(name+" is deleted");
    }
    public void display(){
        node temp=head;
        while(temp!=null){
        System.out.println(temp.name+" "+temp.num);
        temp=temp.next;
        }
    }
    public static void main(String[] args) {
        q8 s=new q8();
        s.add("Dinesh", "4569882235");
        s.add("Vishnu", "894561235");
        s.add("Avinash", "8561237895");
        s.add("Shiva", "4561236895");
        s.display();
        s.delete("avinash");
        s.display();
    }
}