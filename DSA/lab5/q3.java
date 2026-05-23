import java.util.*;

public class q3 {
    public static String convertTopostfix(String infixExpression){
        Stack<Character> stack = new Stack<>();
        String postfixExpression = "";
        for(int i=0;i<infixExpression.length();i++){
            char ch = infixExpression.charAt(i);
            if(Character.isLetterOrDigit(ch)){
                postfixExpression += ch;
            }
            else if(ch == '('){
                stack.push(ch);
            }
            else if(ch == ')'){
                while(!stack.isEmpty() && stack.peek() != '('){
                    postfixExpression += stack.pop();
                }
                stack.pop();
            }
            else{
                while(!stack.isEmpty() && precedence(ch) <= precedence(stack.peek())){
                    postfixExpression += stack.pop();
                }
                stack.push(ch);
            }
        }
        while(!stack.isEmpty()){
            postfixExpression += stack.pop();
        }
        return postfixExpression;
    }

    public static int precedence(char ch){
        switch(ch){
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2; 
            case '^':
                return 3;
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the infix expression: ");
        String infixExpression = sc.nextLine();
        System.out.println("The postfix expression is: "+convertTopostfix(infixExpression));
        sc.close();
    }
}