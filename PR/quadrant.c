/*@  ensures 1<=\result<=4;
     behavior one:
        assumes x>=0 && y>=0;
        ensures \result==1;
     behavior two:
        assumes x<0 && y>=0;
        ensures \result==2;
     behavior three:
        assumes x<0 && y<0;
        ensures \result==3;
     behavior four:
        assumes x>=0 && y<0;
        ensures \result==4;
     complete behaviors one,two,three,four;
     disjoint behaviors one,two,three,four;
*/
int quadrant(int x,int y)
{
   if(x>=0){
     if(y>=0){
        return 1;
     }
     return 4;
   }
   else{
      if(y>=0){
        return 2;
      }
      return 3;
   }
}

