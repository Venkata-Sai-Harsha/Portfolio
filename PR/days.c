/*@   requires 1<=month<=12;
      behavior one:
        assumes month \in {1,3,5,7,8,10,12};
        ensures \result==31;
      behavior two:
        assumes month \in {4,6,9,11};
        ensures \result==30;
      behavior three:
        assumes month==2;
        ensures \result==28;
      complete behaviors one,two,three;
      disjoint behaviors one,two,three;
*/
int day_of(int month){
  int days[]= {31,28,31,30,31,30,31,31,30,31,30,31} ;
  return days[month-1];
}
