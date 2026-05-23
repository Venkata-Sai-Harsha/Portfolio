import java.util.*;

public class q2 {
    private Stack<Integer> stack;

    public q2() {
        stack = new Stack<>();
    }

    public int evaluate(String expression) {
        Scanner sc = new Scanner(expression);
        while (sc.hasNext()) {
            if (sc.hasNextInt()) {
                stack.push(sc.nextInt());
            } 
            else {
                int b = stack.pop();
                int a = stack.pop();
                String operator = sc.next();

                switch (operator) {
                    case "+":
                        stack.push(a + b);
                        break;
                    case "-":
                        stack.push(a - b);
                        break;
                    case "*":
                        stack.push(a * b);
                        break;
                    case "/":
                        stack.push(a / b);
                        break;
                    default:
                        throw new IllegalArgumentException("Invalid operator: " + operator);
                }
            }
        }
        return stack.pop();
    }

    public static void main(String[] args) {
        q2 q = new q2();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the postfix expression: ");
        String expression = scanner.nextLine();
        
        int result = q.evaluate(expression);
        System.out.println("Result: " + result);  
    }
}