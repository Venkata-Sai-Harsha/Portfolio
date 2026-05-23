/*@ requires \valid(a) && \valid(b);
    assigns \nothing;
    behavior one:
      assumes   *a <= *b;
      ensures \result==*b;
    behavior two:
      assumes *a>=*b;
      ensures \result==*a;
    ensures \result==*a || \result==*b;
        disjoint behaviors one,two;
        complete behaviors one,two;
*/
int max_ptr(int *a,int *b){
   return (*a<*b)?*b:*a;
}

extern int h;
int main(){
  h=42;
  int a=24;
  int b=42;
  int x=max_ptr(&a,&b);
  //@ assert x==42;
  //@ assert h==42;
}
