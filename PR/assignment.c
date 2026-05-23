/*@ requires y>2;
ensures \result > 7;
*/
int fun(int x,int y){
	x=y+5;
	return x;
}
