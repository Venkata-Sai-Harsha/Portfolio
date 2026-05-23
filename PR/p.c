/*@ requires n > 0;
    requires \valid(arr+(0..n-1));
    behavior equal:
        assumes \forall integer i;
        0 <= i < n ==> arr[i] == i;
        ensures \result == 1;
    behavior not_equal:
        assumes \exists integer i;
        0 <= i < n && arr[i] != i;
        ensures \result == 0;
    complete behaviors equal,not_equal;
    disjoint behaviors equal,not_equal;
*/

int fun(int arr[] ,int n)
{
    /*@ loop invariant \forall integer j; 
            0 <= j < i ==> arr[j] == j;
        loop invariant 0 <= i <= n;
        loop assigns i;
        loop variant n-i;
    */

    for(int i = 0 ;i<n;i++){
        if(arr[i]!=i){
            return 0;
        }
    }
    return 1;
}