import java.util.*;

public class stacksort {
    class Node{
        int data;
        Node next;
        Node(int data){
            this.data = data;
        }
    }

    Node top;
    int size;

    public void push(int data){
        Node node = new Node(data);
        node.next = top;
        top = node;
        size++;
    }

    public int pop(){
        if(top == null){
            System.out.println("Stack is empty");
            return -1;
        }
        int data = top.data;
        top = top.next;
        size--;
        return data;
    }

    public int peek(){
        if(top == null){
            System.out.println("Stack is empty");
            return -1;
        }
        return top.data;
    }

    public boolean isEmpty(){
        return top == null;
    }

    public void print(){
        Node temp = top;
        while(temp != null){
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }

    public void sort(){
        if(top == null){
            System.out.println("Stack is empty");
            return;
        }
        int temp = pop();
        sort();
        insert(temp);
    }

    public void insert(int data){
        if(top == null || data > peek()){
            push(data);
            return;
        }
        int temp = pop();
        insert(data);
        push(temp);
    }


    public static void main(String[] args) {
        stacksort stack = new stacksort();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of stack: ");
        int n = sc.nextInt();
        System.out.println("Enter the elements of stack: ");
        for(int i = 0; i < n; i++){
            stack.push(sc.nextInt());
        }
        System.out.println("Stack before sorting: ");
        stack.print();
        stack.sort();
        System.out.println("\nStack after sorting: ");
        stack.print();
        sc.close();
    }
}