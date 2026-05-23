/*@ requires a>0;
ensures \result > 1;
*/
int next(int a){
	//@ assert a>0;
	a=a+1;
	return a;
}
