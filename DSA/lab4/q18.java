public class q18 {
    int[] arr;
    int size;
    int top1, top2;

    q18(int n){
        size = n;
        arr = new int[n];
        top1 = n/2+1;
        top2 = n/2;
    }

    void push1(int x){
        if (top1 > 0){
            top1--;
            arr[top1] = x;
        }
        else{
            System.out.println("Stack full ");
        }
    }

    void push2(int x){
        if (top2 < size-1){
            top2++;
            arr[top2] = x;
        }
        else{
            System.out.println("Cannot push ");
        }
    }

    int pop1(){
        if(top1 <= size/2){
            int x = arr[top1];
            top1++;
            return x;
        }
        System.out.print("Cannot push ");
        return -1;
    }

    int pop2(){
        if(top2 >= size/2+1){
            int x = arr[top2];
            top2--;
            return x;
        }
        System.out.print("Stack is empty");
        return -1;
    }
}
