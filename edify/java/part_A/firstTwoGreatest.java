public class firstTwoGreatest {
    public static void main(String[] args) {
        int[] arr = {3, 5, 7, 2, 8, 6};
        int first = Integer.MIN_VALUE;
        int second = Integer.MIN_VALUE;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > first) {
                second = first;
                first = arr[i];
            } else if (arr[i] > second && arr[i] != first) {
                second = arr[i];
            }
        }

        System.out.println("The two greatest numbers are: " + first + " and " + second);
    }
    
}
