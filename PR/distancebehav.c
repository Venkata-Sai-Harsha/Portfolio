#include <limits.h>
/*@
requires 0<=a<=INT_MAX;
requires 0<=b<=INT_MAX;
behavior x:
   assumes (b>a);
   ensures \result ==(b-a);
behavior y:
   assumes (a>b);
   ensures \result ==(a-b);
behavior z:
   assumes (a==b);
   ensures \result ==0;
disjoint behaviors;
*/
int distance(int a,int b){
    if(a<b) return b-a;
    else return a-b;
}
