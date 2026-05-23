public class StackInt {
    int[] arr;
    int top;

    StackInt(int size){
        arr = new int[size];
        top = -1;
    }

    StackInt(){
        arr = new int[10];
        top = -1;
    }

    public int set(){
        if(top == -1){
            return -1;
        }
        return arr[top];
    }

    public void print(){
        for(int i=top; i>=0; i--){
            System.out.println(arr[i]+" ");
        }
    }

    public void push(int item){
        if(top < arr.length-1){
            top++;
            arr[top] = item;
        }
        else{
            System.out.println(".·´¯`(>▂<)´¯`·. Cannot push ");
            System.out.println("Current stack : ");
            print();
        }
    }

    public int getTop(){
        return top;
    }

    public int pop(){
        if(top == -1){
            System.out.println("Can't pop, the stack is already empty");
            System.out.println("What are you trying to remove＼（〇_ｏ）／?");
            return -1;
        }
        int x = arr[top];
        System.out.println("Popped : " + x);
        top--;
        return x;
    }

    public int peek(){
        if(top == -1){
            System.out.println("There is nothing there to peek");
            return -1;
        }
        System.out.println(arr[getTop()]);
        return arr[getTop()];
    }

    public boolean equals(StackInt x){
        if(this.top != x.top){
            return false;
        }
        for(int i=this.top; i>=0; i--){
            if(this.arr[i] != x.arr[i]){
                return false;
            }
        }
        return true;
    }

    public int getminElement(){
        int min = -1;
        for(int i=0; i<=top; i++){
            if(arr[i] < min){
                min = arr[i];
            }
        }
        return min;
    }

    public StackInt copyStack(){
        StackInt ans = new StackInt(this.arr.length);
        for(int i=0; i<=top; i++){
            ans.push(this.arr[i]);
        }
        return ans;
    }

    public void reverse(){
        for(int i=0; i<=top/2; i++){
            int temp = arr[i];
            arr[i] = arr[top-i];
            arr[top-i] = temp;
        }
    }

    public int removeMiddleElement(){
        int x = arr[getTop()/2];
        for(int i=getTop()/2; i<top; i++){
            arr[i] = arr[i+1];
        }
        top--;
        return x;
    }

    public int pop1(){
        if(top == -1){
            System.out.println("Can't pop, the stack is already empty ");
            System.out.println("What are you trying to remove ＼（〇_ｏ）／ ?");
            return -1;
        }
        int x = arr[top];
        top--;
        return x;
    }

    public int peek1(){
        return arr[getTop()];
    }

    public void sort(){
        for (int i = 0; i <= top; i++) {
            for (int j = i+1; j <= top; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}