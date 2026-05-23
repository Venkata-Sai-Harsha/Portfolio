/*@ requires n1>0 && n2>0;
    requires \valid(a+(0..n1-1));
    requires \valid(b+(0..n2-1));
    behavior equal:
        assumes \forall integer i; 
        0<=i<n1 ==> i!=n2;
            ensures \result<==> n1==n2;
    behavior not_equal:
         assumes \exists integer i; 
         0<=i<n1 && i==n2;
            ensures \result==0;
    complete behaviors;
    disjoint behaviors;
*/
int equal(int a[], int b[], int n1, int n2){
    /*@ loop invariant 0<=i<=n1;
        loop invariant \forall integer j; 
        0<=j<i ==> n1==n2;
        loop assigns i;
        loop variant n1-i;
    */
    for (int i = 0; i < n1; i++){
        if (i==n2){
            return 0;
        }
    }
    return n1==n2;
}