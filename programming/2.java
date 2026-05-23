class RunnableFactorial implements Runnable {
    private int n;

    public RunnableFactorial(int n) {
        this.n = n;
    }
    private long factorial(int n) {
        long result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }
    public void run() {
        long result = factorial(n);
        System.out.println(Thread.currentThread().getName() + ": Factorial of " + n + " is " + result);
    }
    public static void main(String[] args) {
        Thread t1 = new Thread(new RunnableFactorial(5));
        Thread t2 = new Thread(new RunnableFactorial(7));
        Thread t3 = new Thread(new RunnableFactorial(10));
        t1.start();
        t2.start();
        t3.start();
    }
}
