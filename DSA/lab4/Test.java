import java.util.*;
public class Test {
    public static void main(String args[]){
        System.out.println("Stack 1 : ");
        StackInt si1 = new StackInt(5);
        System.out.println("Stack top is : " + si1.top);
        System.out.println("Stack size is : " + si1.arr.length);

        System.out.println("\nStack 2 : ");
        StackInt si2 = new StackInt();
        System.out.println(si2.arr.length);

        System.out.println("\nStack 3 : ");
        StackInt si3 = new StackInt();
        si3.push(100);
        System.out.println("Current stack : ");
        si3.print();
        si3.push(200);
        System.out.println("Current stack : ");
        si3.print();

        System.out.println("\nStack 4 : ");
        StackInt si4 = new StackInt(2);
        si4.push(500);
        si4.push(600);
        si4.push(700);
        System.out.println("Top is : " + si4.getTop());

        System.out.println("\nStack 5 : ");
        StackInt si5 = new StackInt(4);
        si5.push(11);
        si5.push(22);
        si5.push(33);
        si5.push(44);
        System.out.println("The current stack : ");
        si5.print();
        si5.pop();
        si5.pop();
        System.out.println("The current stack : ");
        si5.print();
        si5.pop();
        si5.pop();
        si5.pop();

        System.out.println("\nStack 6 : ");
        StackInt si6 = new StackInt(4);
        si6.push(11);
        si6.push(22);
        si6.push(33);
        si6.push(44);
        si6.print();

        System.out.println("\nStack 7 : ");
        StackInt si7 = new StackInt(5);
        si7.push(11);
        si7.push(22);
        si7.push(33);
        si7.push(44);
        si7.push(55);
        si7.print();

        System.out.println("\nIs Stack 6 and Stack 7 are equal : \nAns) "+si6.equals(si7));
        si6.pop();
        System.out.println("Now after popping an element : ");
        System.out.println("Is Stack 6 and Stack 7 are equal : \nAns) "+si6.equals(si7));

        StackInt si8 = si3.copyStack();
        System.out.println("\nStack 8 after copying it from stack 3 : ");
        si8.print();

        System.out.println("\nStack 7 after reversing : ");
        si7.reverse();
        si7.print();

        System.out.println("\nStack 9 : ");
        StackInt si9 = new StackInt(6);
        si9.push(1);
        si9.push(2);
        si9.push(3);
        si9.push(4);
        si9.push(5);
        si9.push(6);
        System.out.println("Initial stack : ");
        si9.print();
        System.out.println("After removing middle element once : ");
        si9.removeMiddleElement();
        si9.print();
        System.out.println("After removing middle element again : ");
        si9.removeMiddleElement();
        si9.print();

        System.out.println("\nStack 10 : ");
        StackInt si10 = new StackInt(8);
        si10.push(34);
        si10.push(2);
        si10.push(31);
        si10.push(98);
        si10.push(54);
        si10.push(76);
        si10.push(78);
        si10.push(66);
        System.out.println("\nInitial stack : ");
        si10.print();
        si10.sort();
        System.out.println("After sorting : ");
        si10.print();

        System.out.println("\nTwo Stacks in a Single Array : ");

        q18 si11 = new q18(9);
        si11.push1(5);
        si11.push2(10);
        si11.push1(54);
        si11.push2(75);
        si11.push1(14);
        si11.push2(7);
        si11.push2(71);
        si11.push1(6);
        System.out.println("Popped element from stack1 is : " + si11.pop1());
        si11.push2(40);
        System.out.println("Popped element from stack2 is : " + si11.pop2());

    }
}
