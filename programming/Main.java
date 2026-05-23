//3a
// class Counter {
//     private int count;
    
//     public Counter() { 
//         count = 0; 
//     }
    
//     public synchronized void increment() { 
//         count = count + 1; 
//     }
    
//     public synchronized void decrement() { 
//         count = count - 1; 
//     }
    
//     public synchronized int getCount() { 
//         return count; 
//     }
// }

// class Incrementor extends Thread {
//     private Counter counter;
    
//     public Incrementor(Counter counter) { 
//         this.counter = counter; 
//     }
    
//     public void run() {
//         for (int i = 0; i < 10; i++) {
//             counter.increment();
//             System.out.println(Thread.currentThread().getName() + ": " + counter.getCount());
//         }
//     }
// }

// class Decrementor extends Thread {
//     private Counter counter;
    
//     public Decrementor(Counter counter) { 
//         this.counter = counter; 
//     }
    
//     public void run() {
//         for (int i = 0; i < 10; i++) {
//             counter.decrement();
//             System.out.println(Thread.currentThread().getName() + ": " + counter.getCount());
//         }
//     }
// }

// public class Main {
//     public static void main(String[] args) {
//         Counter counter = new Counter();
//         Incrementor incThread = new Incrementor(counter);
//         Decrementor decThread = new Decrementor(counter);

//         incThread.start();
//         decThread.start();
//     }
// }





//3b
class Counter {
    private int count;

    Counter() {
        count = 0;
    }

    public void increment() {
        synchronized (this) {
            count = count + 1;
        }
    }

    public void decrement() {
        synchronized (this) {
            count = count - 1;
        }
    }

    public int getCount() {
        synchronized (this) {
            return count;
        }
    }
}

class Incrementor extends Thread {
    private Counter counter;

    Incrementor(Counter counter) {
        this.counter = counter;
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            counter.increment();
            System.out.println(Thread.currentThread().getName() + ": " + counter.getCount());
        }
    }
}

class Decrementor extends Thread {
    private Counter counter;

    Decrementor(Counter counter) {
        this.counter = counter;
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            counter.decrement();
            System.out.println(Thread.currentThread().getName() + ": " + counter.getCount());
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Counter counter = new Counter();
        Incrementor incThread = new Incrementor(counter);
        Decrementor decThread = new Decrementor(counter);

        incThread.start();
        decThread.start();
    }
}
