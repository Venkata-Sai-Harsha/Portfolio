package practise;
//stack using queue
import java.util.*;
import java.io.*;
import java.util.Stack;

public class e3{
    //using two queues
    //-----------------------------------------------------
    static class Stack{
        static Queue<Integer> q1=new LinkedList<Integer>();
        static Queue<Integer> q2=new LinkedList<Integer>();
        static int curr_size,size;
        Stack(){
            curr_size=0;
        }
        static void push(int x){
            curr_size++;
            q2.add(x);
            while(!q1.isEmpty()){
                q2.add(q1.peek());
                q1.remove();
            }
            Queue<Integer> q=q1;
            q1=q2;
            q2=q;
        }
        static void pop(){
            if(q1.isEmpty()){
                return;
            }
            q1.remove();
            curr_size--;
        }
        static int top(){
            if(q1.isEmpty()){
                return -1;
            }
            return q1.peek();
        }
        static int size(){
            return curr_size;
        }
    }

    //using single queue
    //-----------------------------------------------------
    static class stack1{
        static Queue<Integer> q=new LinkedList<Integer>();
        static void push(int x){
            int size=q.size();
            q.add(x);
            for(int i=0;i<q.size()-1;i++){
                q.add(q.peek());
                q.remove();
            }
        }
        static void pop(){
            if(q.isEmpty()){
                return;
            }
            q.remove();
        }
        static int top(){
            if(q.isEmpty()){
                return -1;
            }
            return q.peek();
        }
        static int size(){
            return q.size();
        }
    }

    //queue using stack
    //making enqueue costly
    //-----------------------------------------------------
    static class queue{
        static Stack<Integer> s1 = new Stack<Integer>(); 
        static Stack<Integer> s2 = new Stack<Integer>(); 
        static void enqueue(int x){
            while(!s1.isEmpty()){
                s2.push(s1.pop());
            }
            s1.push(x);
            while(!s2.isEmpty()){
                s1.push(s2.pop());
            }
        }
        static int dequeue(){
            if(s1.isEmpty()){
                return -1;
            }
            int x=s1.peek();
            s1.pop();
            return x;
        }
        static int front(){
            if(s1.isEmpty()){
                return -1;
            }
            return s1.peek();
        }
        static int size(){
            return s1.size();
        }
    }

    //making dequeue costly
    //-----------------------------------------------------
    static class stack1{
        static Stack<Integer> s1 = new Stack<Integer>();
        static Stack<Integer> s2 = new Stack<Integer>();
        static void enqueue(int x){
            s1.push(x);
        }
        static int dequeue(){
            if(s1.isEmpty() && s2.isEmpty()){
                return -1;
            }
            if(s2.isEmpty()){
                while(!s1.isEmpty()){
                    s2.push(s1.pop());
                }
            }
            int x=s2.peek();
            s2.pop();
            return x;
        }
        static int front(){
            if(s1.isEmpty() && s2.isEmpty()){
                return -1;
            }
            if(s2.isEmpty()){
                while(!s1.isEmpty()){
                    s2.push(s1.pop());
                }
            }
            return s2.peek();
        }
        static int size(){
            return s1.size()+s2.size();
        }
    }

    //queue using stack with single stack
    //-----------------------------------------------------
    
    public static void main(String[] args) {
        Stack s=new Stack();
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        System.out.println("current size: "+s.size());
        System.out.println(s.top());
        s.pop();
        System.out.println(s.top());
        s.pop();
        System.out.println(s.top());
        System.out.println("current size: "+s.size());
        System.out.println("using single queue");   
        stack1 s1=new stack1();
        s1.push(1);
        s1.push(2);
        System.out.println("current size: "+s1.size());
        s1.push(3);
        s1.push(4);
        System.out.println("current size: "+s1.size());
        System.out.println(s1.top());
        s1.pop();
        System.out.println(s1.top());
        s1.pop();
        System.out.println(s1.top());
        System.out.println("current size: "+s1.size());

    }
}