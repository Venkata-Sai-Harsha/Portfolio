/*@
requires x>-1000 && x <=1000;
requires y>-1000 && y <=1000;
ensures x==0 ==>\result==y;
ensures y==0 ==>\result==x;
*/
int add(int x, int y){
    return x+y;
}
