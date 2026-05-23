struct Counter{int seconds;};
struct Counter c;

/*@ requires c.seconds >= 0;
    ensures c.seconds >= 0 && c.seconds < 60;
    behavior normal:
        assumes c.seconds < 59;
        ensures c.seconds == \old(c.seconds)+1;
    behavior overflow:
        assumes c.seconds == 59;
        ensures c.seconds == 0;
    assigns c;
*/
void tick(){c.seconds = (c.seconds+1) % 60;}

