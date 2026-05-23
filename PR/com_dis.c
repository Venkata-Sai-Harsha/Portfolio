/*@ behavior positive_a:
        assumes a>0;
        ensures \result == a+1;
    behavior negative_a:
        assumes a<=0;
        ensures \result == a+2;
	complete behaviors positive_a, negative_a;
	disjoint behaviors positive_a, negative_a;
*/
int next(int a){
        return a>0 ? a+1 : a+2;
}
