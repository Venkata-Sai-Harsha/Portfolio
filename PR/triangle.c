/*@
requires 0<=first<=180 && 0<=second<=180;
ensures (first+second+\result)==180;
*/
int last_angle(int first, int second){
    return 180-first-second;
}
