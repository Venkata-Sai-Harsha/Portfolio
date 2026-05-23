/*@
requires a>=0 && b>=0;
ensures (a<b) ==>\result==(b-a);
ensures (b<a) ==>\result==(a-b);
*/
int distance(int a,int b){
    if(a<b){
    	return b-a;
    }
    else{
    	return a-b;
    }
}
