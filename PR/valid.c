/*@ requires \valid(ptr);
ensures \result == *ptr + 1;
*/
int next(int *ptr){
	return *ptr+1;
}

