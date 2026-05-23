package lab6;


public class Test extends QueueInt {
    public static void main(String[] args) {
        QueueInt qi = new QueueInt();
        System.out.println("Queue Front is " + qi.front + " and Rear is " + qi.rear);
        System.out.println("Length of qi is " + qi.array.length);
        QueueInt qi2 = new QueueInt(15);
        System.out.println("Length of qi2 is " + qi2.array.length);
        System.out.print("Elements in Queue are: ");
        qi.enqueue(100);
        qi.enqueue(200);
        qi.enqueue(900);
        qi.enqueue(300);
        qi.print();
        if (qi == qi2)
            System.out.println("Both qi1 and qi2 are same");
        else
            System.out.println("Both qi1 and qi2 are not the same");
        System.out.println();
        System.out.print("Elements after dequeue are: ");
        int item = qi.dequeue();
        qi.print();
        System.out.println();
        System.out.print("Elements after dequeue are: ");
        int item1 = qi.dequeue();
        qi.print();
        System.out.println();
        System.out.println("Top Element is " + qi2.getFront());
    }
}
