/*@ requires class_held > 0;
    requires 0 <= class_attended <= class_held;
    requires marks > 0;
    ensures \result == 0 || \result == marks + 5;
    assigns \nothing;
*/
int fun(int class_held,int class_attended,int marks){
    int percent = class_attended*100/class_held;
    if(percent > 75){
        return marks+5;
    }
    else{
        return 0;
    }
}