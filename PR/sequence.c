/*@ requires z>1;
ensures \result > 7;
*/
int fun(int x,int y,int z){
	y=z*2;
	x=y+5;
	return x;
}
