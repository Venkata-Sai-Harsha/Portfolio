/*@ requires z>-1;
ensures \result>5;
*/
int fun(int x,int y,int z){
	x=z+1;
	y=x+5;
	return y;
}
