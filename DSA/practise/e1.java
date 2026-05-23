package practise;

public class e1 {
    class Node{
        int data;
        Node next;
        Node(int data){
            this.data = data;
            this.next = null;
        }
    }
    class Queue{
        Node front, rear;
        Queue(){
            this.front = this.rear = null;
        }
    }
    void enqueue(Queue q, int data){
        Node temp = new Node(data);
        if(q.rear == null){
            q.front = q.rear = temp;
            return;
        }
        q.rear.next = temp;
        q.rear = temp;
    }
    Node dequeue(Queue q){
        if(q.front == null){
            return null;
        }
        Node temp = q.front;
        q.front = q.front.next;
        if(q.front == null){
            q.rear = null;
        }
        return temp;
    }
    void display(Queue q){
        Node temp = q.front;
        while(temp != null){
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        e1 obj = new e1();
        Queue q = obj.new Queue();
        obj.enqueue(q, 10);
        obj.enqueue(q, 20);
        obj.enqueue(q, 30);
        obj.enqueue(q, 40);
        obj.enqueue(q, 50);
        obj.display(q);
        Node n = obj.dequeue(q);
        if(n != null){
            System.out.println("Dequeued item is: "+n.data);
        }
        else{
            System.out.println("Queue is empty");
        }
        obj.display(q);
    }
}
