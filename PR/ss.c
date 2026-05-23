/*@ requires n1>0 && n2>0;
    requires \valid(a+(0..n1-1));
    requires \valid(b+(0..n2-1));
    behavior not_equal1:
        assumes n1!=n2;
        ensures \result==0;
    behavior equal:
        assumes \forall integer i; 
            0<=i<n1 ==> a[i]==b[i]; 
        ensures \result==1;
    behavior not_equal:
        assumes \exists integer i; 
            0<=i<n1 && a[i]!=b[i]; 
        ensures \result==0;
    complete behaviors equal, not_equal;
    disjoint behaviors equal, not_equal;
*/

int array(int a[], int b[], int n1, int n2){
    int i;
    if (n1 != n2){
        return 0;
    }
    /*@ loop invariant 0<=i<=n1;
        loop invariant \forall integer j; 
            0<=j<i ==> a[j]==b[j];
        loop assigns i;
        loop variant n1-i;
    */
    for (i = 0; i < n1; i++){
        if (a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}