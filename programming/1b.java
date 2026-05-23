import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class SumCallableTask implements Callable<Long> {
    private int start;
    private int end;
    private String taskName;

    public SumCallableTask(int start, int end, String taskName) {
        this.start = start;
        this.end = end;
        this.taskName = taskName;
    }

    @Override
    public Long call() {
        long sum = 0;
        for (int i = start; i <= end; i++) {
            sum += i;
            try {
                Thread.sleep(2000); // Sleep for 2 seconds
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(3);

        // Create and submit 5 tasks
        for (int i = 0; i < 5; i++) {
            int start = i * 10 + 1;
            int end = (i + 1) * 10;
            SumCallableTask task = new SumCallableTask(start, end, "Task-" + (i + 1));
            executor.execute(() -> {
                try {
                    Long result = task.call();
                    System.out.println(taskName + " - Sum of numbers from " + start + " to " + end + " is: " + result);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            });
        }

        executor.shutdown();
    }
}
