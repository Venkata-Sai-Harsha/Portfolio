#include <limits.h>
/*@
requires *a <= INT_MIN;
requires *b <= INT_MIN;
requires \valid(a) && \valid(b);
requires *a >=0 && *b>=0;
behavior x:
assumes (*a) < (*b);
assigns *a, *b;
ensures (*b) == \old(*a);
ensures (*a) == \old(*b);
disjoint behaviors;
*/
void max(int *a,int *b){
    if(*a<*b){
    	int temp=b;
    	*b=*a;
    	*a=temp;
    }
}
