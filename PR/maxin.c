/*@ requires n>0;
    requires \valid_read(arr+(0..n-1));
    assigns \nothing;
    ensures \forall integer i;
    0<=i<n ==> arr[i]<=arr[\result];
*/
int hi(int arr[],int n){
    int max_ind = 0;
    /*@ loop invariant \forall integer i;
        0<=i<j ==> arr[max_ind]>=arr[i];
        loop invariant 1<=j<=n;
        loop invariant 0<=max_ind<n;
        loop assigns max_ind,j;
        loop variant n-j;
    */
    for(int j=1; j<n;j++){
        if(arr[j] > arr[max_ind]){
            max_ind=j;
        }
    }
    return max_ind;
}