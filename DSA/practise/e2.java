package practise;
import java.util.Stack;

public class e2 {
    public static String reverseString(String input) {
        // Create an empty stack of characters
        Stack<Character> stack = new Stack<>();

        // Push each character from the input string onto the stack
        for (int i = 0; i < input.length(); i++) {
            stack.push(input.charAt(i));
        }

        // Pop each character from the stack and append it to a new string
        StringBuilder reversedString = new StringBuilder();
        while (!stack.isEmpty()) {
            reversedString.append(stack.pop());
        }

        // Convert the StringBuilder object to a string and return it
        return reversedString.toString();
    }

    public static void main(String[] args) {
        String input = "Hello, World!";
        String reversed = reverseString(input);
        System.out.println("Original string: " + input);
        System.out.println("Reversed string: " + reversed);
    }
}