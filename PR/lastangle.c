/*@    requires 0<first+second<180 && first>0 && second>0;
       ensures \result<180 && \result+first+second==180;
*/
int last_angle(int first, int second){
    return 180-first-second;
}
