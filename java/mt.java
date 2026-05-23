import java.util.*;
/*class hi implements Runnable{
    public void run(){
        for(int i=0;i<5;i++){
            System.out.println("hi");
            try{Thread.sleep(500);}catch(Exception e){}
        }
    }
}
class hello implements Runnable{
    public void run(){
        for(int i=0;i<5;i++){
            System.out.println("hello");
            try{Thread.sleep(500);}catch(Exception e){}
        }
    }
}
public class mt {
    public static void main(String[] args) {
        hi obj1=new hi();
        hello obj2=new hello();

        Thread t1= new Thread(obj1);
        Thread t2= new Thread(obj2);

        t1.start();
        try{Thread.sleep(10);}catch(Exception e){}
        t2.start();
    }
}*/


/*Write a multi-threaded java code with one thread printing all even numbers and the other all odd numbers. The output should always be in sequence ie. 0,1,2,3,4.... etc.*/
/*class even implements Runnable{
  public void run(){
      for(int i=0;i<10;i++){
          if(i%2==0){
              System.out.print(i+" ");
              try{Thread.sleep(500);}catch(Exception e){}
          }
      }
  }
}

class odd implements Runnable{
    public void run(){
        for(int i=0;i<10;i++){
            if(i%2!=0){
                System.out.print(i+" ");
                try{Thread.sleep(500);}catch(Exception e){}
            }
        }
    }
}

public class mt {
    public static void main(String[] args) {
        even obj1=new even();
        odd obj2=new odd();

        Thread t1= new Thread(obj1);
        Thread t2= new Thread(obj2);

        t1.start();
        try{Thread.sleep(10);}catch(Exception e){}
        t2.start();
    }
}*/

/*import java.util.*;

class even extends Thread{
    private int n;
    public even (int n)
    {
        this.n=n;
    }
    public void run(){
        System.out.println("Thread 1: ");
        System.out.println("I am Thread1");
        for(int i=1;i<=n;i++){
            System.out.print(i+" ");
            try{
                Thread.sleep(500);
            }catch(Exception e){}
        }
        System.out.println();
    }
}
public class mt {
    public static void main(String[] args) {
        System.out.print("Enter a number:");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        even obj1=new even(n);
        obj1.start();
        try {
            obj1.join();
          } catch (InterruptedException e) {
            e.printStackTrace();
          }
        System.out.println();
        System.out.println("I am main one: ");
        for (int i=n;i>=1;i--){
            System.out.print(i+" ");
            try{
                Thread.sleep(500);
            }catch(Exception e){}
        }
        System.out.println();
        System.out.println("Smallest number is 1");
    }
}*/


/*import java.util.*;
class fibonacci extends Thread{
    private int n;
    public fibonacci (int n)
    {
        this.n=n;
    }
    public void run(){
        int a=0,b=1,c;
        System.out.print(a+" "+b+" ");
        for(int i=3;i<=n;i++){
            c=a+b;
            System.out.print(c+" ");
            a=b;
            b=c;
            try{
                Thread.sleep(500);
            }catch(Exception e){}
        }
        System.out.println();
    }
}

public class mt {
    public static void main(String[] args) {
        System.out.print("Enter a number:");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        fibonacci obj1=new fibonacci(n);
        obj1.start();
    }
}*/

/*public class mt extends Thread {
    public int x,n;
    static int t;

    synchronized public void rndnum(){
        Random rd = new Random();
        n = rd.nextInt(10);
        System.out.println("Randon num: " + n);
    }

    synchronized public void even(){
        if(n%2==0){
            x = n*n;
            System.out.println(Thread.currentThread().getName() + " " + x);
        }
    }

    synchronized public void odd(){
        if(n%2!=0){
            x = n*n*n;
            System.out.println(Thread.currentThread().getName() + " " + x);
        }
    }

    public static void main(String[] args) {
        mt poe = new mt();

        Scanner scan = new Scanner(System.in);
        System.out.print("Enter testcases: ");
        t = scan.nextInt();
        for(int i=0;i<t;i++){
            Thread t1 = new Thread(new Runnable() {
                public void run(){
                    poe.rndnum();
                }
            },"Thread-1");
            try{
                Thread.sleep(500);
            }catch(Exception e){}

            Thread t2 = new Thread(new Runnable() {
                public void run(){
                    poe.even();
                }
            },"Thread-2");
            try{
                Thread.sleep(500);
            }catch(Exception e){}
            
            Thread t3 = new Thread(new Runnable() {
                public void run(){
                    poe.odd();
                }
            },"Thread-3");
            try{
                Thread.sleep(500);
            }catch(Exception e){}
            
            t1.start();
            t2.start();
            t3.start();
        }
        scan.close();
    }
}*/

/*public class mt extends Thread{
    public static int n;
    public void even(){
        for(int i=0;i<n;i++){
            if(i%2==0){
                System.out.print(i+" ");
                try{Thread.sleep(500);}catch(Exception e){}
            }
        }
    }
    public void odd(){
        for(int i=0;i<n;i++){
            if(i%2!=0){
                System.out.print(i+" ");
                try{Thread.sleep(500);}catch(Exception e){}
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a number:");
        n=sc.nextInt();
        mt obj1=new mt();
        Thread t1=new Thread(new Runnable(){
            public void run(){
                obj1.even();
            }
        });
        Thread t2=new Thread(new Runnable(){
            public void run(){
                obj1.odd();
            }
        });
        t1.start();
        try{Thread.sleep(10);}catch(Exception e){}
        t2.start();
    }
}*/

/*public class mt extends Thread { 
    public void run() 
    { 
        System.out.println("CS "); 
        try { 
            Thread.sleep(300); 
        } 
        catch (InterruptedException ie) { 
        } 
        System.out.println("engineering "); 
    } 
    public static void main(String[] args) 
    { 
        mt c1 = new mt(); 
        mt c2 = new mt(); 
        c1.start(); 
        c2.start(); 
        System.out.println(c1.isAlive()); 
        System.out.println(c2.isAlive()); 
    } 
} */


/*Create a thread having your name by implementing Runnable interface. Overriding the run( ) try to print a customized message to print your name. */
/*public class mt extends Thread {
    public void run() {
        System.out.println("from run: ");
        try {
            Thread.sleep(300);
        } catch (InterruptedException ie) {
        }
        System.out.println("Harsha");
    }

    public static void main(String[] args) {
        mt c1 = new mt();
        c1.start();
    }
}*/

/*Create a thread having your name by extending Thread class. Overriding the run( ) try to print a customized message to print your name. */
/*public class mt extends Thread {
    public void run() {
        System.out.print("from run: ");
        try {
            Thread.sleep(300);
        } catch (InterruptedException ie) {
        }
        System.out.println("Harsha");
    }

    public static void main(String[] args) {
        mt c1 = new mt();
        c1.start();
    }
}*/

/*class even implements Runnable{
    public int n;
    public even(int n){
        this.n=n;
    }
    public void run(){
        for(int i=0;i<n;i++){
            if(i%2==0){
                System.out.print(i+" ");
                try{Thread.sleep(500);}catch(Exception e){}
            }
        }
    }
}
  
class odd implements Runnable{
    public int n;
    public odd(int n){
        this.n=n;
    }
    public void run(){
        for(int i=0;i<n;i++){
            if(i%2!=0){
                System.out.print(i+" ");
                try{Thread.sleep(500);}catch(Exception e){}
            }
        }
    }
}
  
public class mt {
    public static void main(String[] args) {
        int n;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a number:");
        n=sc.nextInt();
    
        even obj1=new even(n);
        odd obj2=new odd(n);

        Thread t1= new Thread(obj1);
        Thread t2= new Thread(obj2);

        t1.start();
        try{Thread.sleep(100);}catch(Exception e){}
        t2.start();
    }
}*/

class abc implements Runnable{
    public String n;
    public abc(String n){
        this.n=n;
    }
    public void run(){
        if (n.equals("a") || n.equals("b") || n.equals("c") || n.equals("d")  ){
            System.out.println("great day");
        }
    }
}

class efg implements Runnable{
    public String n;
    public efg(String n){
        this.n=n;
    }
    public void run(){
        if (n.equals("e") || n.equals("f") || n.equals("g") || n.equals("h") || n.equals("i") || n.equals("j") || n.equals("k") ){
            System.out.println("best day");
        }
    }
}

class lmn implements Runnable{
    public String n;
    public lmn(String n){
        this.n=n;
    }
    public void run(){
        if (n.equals("l") || n.equals("m") || n.equals("n") || n.equals("o") || n.equals("p") || n.equals("q") || n.equals("r") ){
            System.out.println("worst day");
        }
    }
}

class stu implements Runnable{
    public String n;
    public stu(String n){
        this.n=n;
    }
    public void run(){
        if (n.equals("s") || n.equals("t") || n.equals("u") || n.equals("v") || n.equals("w") || n.equals("x") || n.equals("y") || n.equals("z")){
            System.out.println("bad day");
        }
    }
}

public class mt {
    public static void main(String[] args) {
        String n;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the loop:");
        int t=sc.nextInt();
        for (int i=0;i<t;i++){
            System.out.print("Enter a character:");
            n=sc.next();
    
            abc obj1=new abc(n);
            efg obj2=new efg(n);
            lmn obj3=new lmn(n);
            stu obj4=new stu(n);

            Thread t1= new Thread(obj1);
            Thread t2= new Thread(obj2);
            Thread t3= new Thread(obj3);
            Thread t4= new Thread(obj4);

            t1.start();
            try{Thread.sleep(100);}catch(Exception e){}
            t2.start();
            try{Thread.sleep(100);}catch(Exception e){}
            t3.start();
            try{Thread.sleep(100);}catch(Exception e){}
            t4.start();
            try{Thread.sleep(100);}catch(Exception e){}
            sc.close();
        }
    }
}


/*class abc implements Runnable{
    public void run(){
        System.out.println("great day");
    }
}

class efg implements Runnable{
    public void run(){
        System.out.println("best day");
    }
}

class lmn implements Runnable{
    public void run(){
        System.out.println("worst day");
    }
}

class stu implements Runnable{
    public void run(){
        System.out.println("bad day");
    }
}

public class mt {
    public static void main(String[] args) {
        String n;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a character:");
        n=sc.next();
        int a;
        a = n.charAt(0);
        
        if (a>=97 && a<=100){   
            abc obj1=new abc();
            Thread t1= new Thread(obj1);
            t1.start();
        }
        else if (a>=101 && a<=107){
            efg obj2=new efg();
            Thread t2= new Thread(obj2);
            t2.start();
        }
        else if (a>=108 && a<=114){
            lmn obj3=new lmn();
            Thread t3= new Thread(obj3);
            t3.start();
        }
        else if (a>=115 && a<=122){
            stu obj4=new stu();
            Thread t4= new Thread(obj4);
            t4.start();
        }
        else 
        {
            System.out.println("Invalid input");
        }
    }
}*/

