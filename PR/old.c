int a;
//@ ensures a == \old(a)+1;
void increment(){
	a++;
}
