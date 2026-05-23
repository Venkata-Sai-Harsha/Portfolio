/*@ requires n >= 0;
    requires \valid(arr + (0..n-1));
    assigns arr[0..n-1];
    ensures \forall integer i; 
        0 <= i < n ==> arr[i] == 0;
*/
void reset_array(int arr[], int n) {
    /*@ loop invariant 0 <= i <= n;
        loop invariant \forall integer j; 
            0 <= j < i ==> arr[j] == 0;
        loop assigns i, arr[0..n-1];
        loop variant n - i;
    */
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
}