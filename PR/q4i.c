/*@ requires y>5 && x==5;
ensures \result>x;
*/
int fun(int x,int y){
	x=5;
	return y;
}
