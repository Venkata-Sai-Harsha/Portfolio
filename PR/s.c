struct Counter
{
	int seconds;
};
struct Counter c;

/*@  
requires c.seconds>=0;
behavior one_c.seconds:
	assumes c.seconds>=0 && c.seconds < 59;
	ensuresc.seconds == \old(c.seconds)+1;
behavior two_c.seconds:
	assumes c.seconds==59;
	ensurec.seconds==0;
complete behaviors one_c.seconds, two_c.seconds;
disjoint behaviors one_c.seconds, two_c.seconds;
ensures c.seconds>=0 && c.seconds < 60; 
*/

void tick()
{
	c.seconds=(c.seconds+1)%60;
}
