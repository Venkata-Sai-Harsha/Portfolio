/*@
requires \valid(q) && \valid(r);
requires \separated(q,r);
requires x>0 && y>0;
assigns *q,*r;
ensures *q==x/y;
ensures *q>=0;
ensures *r==x%y;
ensures *r>=0;
*/
void div_rem(unsigned x,unsigned y,unsigned* q,unsigned* r){
    *q=x/y;
    *r=x%y;
}
