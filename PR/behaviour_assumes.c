/*@ behavior positive_a:
	assumes a>0;
	ensures \result == a+1;
*/
int next(int a){
	if(a>0)
	  return a+1;
	else
	  return a;
}
