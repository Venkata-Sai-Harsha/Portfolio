struct Counter{
	int seconds,minutes,hours;
};
struct Counter c;
// global
/*@ behavior one:
	assumes 0<= c.seconds<59;
	ensures c.seconds ==\old(c.seconds)+1;
    behavior two:
	assumes c.seconds == 59;
	ensures c.seconds == 0;
	 behavior three:
        assumes 0<= c.minutes < 59;
        ensures c.minutes ==\old(c.minutes)+1;
    behavior four:
        assumes c.minutes == 59;
        ensures c.minutes == 0;
    behavior five:
        assumes 0<= c.hours < 23;
        ensures c.hours ==\old(c.hours)+1;
    behavior six:
        assumes c.hours == 24;
        ensures c.hours == 0;
*/
void tick(){
	c.seconds = (c.seconds+1) % 60;
	c.minutes = (c.minutes+1) % 60;
        c.hours = (c.hours+1) % 24;
}
