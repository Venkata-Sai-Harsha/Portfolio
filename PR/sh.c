/*@
    requires n>0;
    requires \valid_read(arr+(0..n-1));
    ensures \forall integer i;
    0<= i < n ==> arr[n-1] >= arr[i];
*/
void selection_sort(int arr[],int n){
    int maxi = arr[0];
    int store = 0;
    /*@
        loop invariant \forall integer i;
        0<= i < j ==> maxi >= arr[i];
        loop invariant 1<= j <=n;
        loop invariant 0<= store < j;
        loop invariant arr[store] == maxi;
        loop assigns j,maxi,store;
        loop variant n-j;
    */
    for(int j=1;j<n;j++){
        if(arr[j]>maxi){
            maxi = arr[j];
            store = j;
        }
    }
    int temp = arr[store];
    arr[store] = arr[n-1];
    arr[n-1] = temp; 
}