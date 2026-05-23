/*@ requires 1<= n<= 3;
ensures\result == n*(n+1)/2;
*/
int sigma(int n){
	int i = 1, s = 0;
	if (i<= n){s = s + i; i = i + 1;}
	if (i<= n){s = s + i; i = i + 1;}
	if (i<= n){s = s + i;}
	return s;
}
