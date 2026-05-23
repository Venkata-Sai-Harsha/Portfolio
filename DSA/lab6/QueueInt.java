package lab6;
public class QueueInt {
    int[] array = new int[5];
    int rear = -1;
    int front = -1;

    QueueInt() {
        array = new int[10];
        front = -1;
        rear = -1;
    }

    QueueInt(int sz) {
        array = new int[sz];
        front = -1;
        rear = -1;
    }

    public boolean isEmpty() {
        return rear == -1;
    }

    public void print() {
        if (isEmpty()) {
            System.out.println("Cannot print element as queue is empty");
        }
        for (int i = 0; i < rear + 1; i++) {
            System.out.print(array[i] + " ");
            array[i] = array[i + 1];
        }
    }

    public void enqueue(int data) {
        if (rear == (array.length) - 1) {
            System.out.println("Cannot insert element as queue is full");
        } else {
            rear++;
            array[rear] = data;
        }
    }

    public int getFront() {
        if (isEmpty()) {
            System.out.print("Cannot peek element as queue is empty so ");
            return -1;
        } else {
            return array[0];
        }
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Cannot remove element as queue is empty");
            return -1;
        } else {
            int front = array[0];
            // Moving all elements to front by 1
            for (int i = 0; i < rear; i++) {
                array[i] = array[i + 1];
            }
            rear--;
            return front;
        }
    }

    public boolean equals(QueueInt another) {
        if (array.equals(another))
            System.out.printf("queue1 and queue2 are equal");

        else
            System.out.printf("queue1 and queue2 are not equal\n");
        return true;
    }

}