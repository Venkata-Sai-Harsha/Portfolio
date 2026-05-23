/*@ requires y>=0 && x>0;
ensures \result>0;
*/
int fun(int x,int y){
	if(y<0){
	  x=y+1;
	}
	return x;
}
