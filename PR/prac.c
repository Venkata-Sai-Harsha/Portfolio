/*@ requires n>0;
    requires k>0;
    requires \valid(arr+(0..n-1));
    ensures \forall integer i;
    0<= i < k ==> arr[k] >= arr[i]; 
*/

void inner_loop(int arr[],int n,int k){

    /*@ loop invariant \forall integer i;
        0<= i < j ==> arr[j] >= arr[i];
        loop invariant 0<= j <= k;
        loop assigns j,arr[0..j+1];
        loop variant k-j; 
    */

   for(int j=0;j<k;j++){
        if(arr[j]>arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}