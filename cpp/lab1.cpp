//1

//2
/*#include <iostream>

using namespace std;

class Rectangle{
    private:
        float length;
        float breadth;
    public:
        Rectangle(float l,float b){
            length=l;
            breadth=b;
        }
        Rectangle(){
            length=0;
            breadth=0;
        }
        Rectangle(Rectangle &r){
            length=r.length;
            breadth=r.breadth;
        }
        ~Rectangle(){
            cout<<"You Just Got Destroyed X_X"<<endl;
        }
        float area(){
            return length*breadth;
        }
        void display(){
            cout<<"Length: "<<length<<endl;
            cout<<"Breadth: "<<breadth<<endl;
            cout<<"Area: "<<area()<<endl;
        }
};


int main(){
    cout<<"Rectangle 1"<<endl;
    float l,b;
    cout<<"Enter length: ";
    cin>>l;
    cout<<"Enter breadth: ";
    cin>>b;
    cout<<endl;
    Rectangle r1(l,b);
    Rectangle r2(r1);
    Rectangle r3;
    cout<<"Rectangle 1 : Parametarized"<<endl;
    r1.display();
    cout<<endl;
    cout<<"Rectangle 2 : Copy"<<endl;
    r2.display();
    cout<<endl;
    cout<<"Rectangle 3 : Default"<<endl;
    r3.display();
    cout<<endl;
    return 0;
}*/

//3
/*#include <iostream>
using namespace std;
class Counter{
    public:
       int c;
       void Init(){
           c=0;
        }
       int count(){
           c=c+1;
        }
       int display(){
           cout << "Counts till now:" <<c<<endl;
        }
};
int main(){
    Counter c1;
    c1.Init();
    int i,n;
    cout << "Enter 1 to count and 2 to display and 3 to exit" << endl;
    while(true){
        cin >> i;
        if(i==1){
            c1.count();
        }
        else if(i==2){
            c1.display();
        }
        else if(i==3){
            c1.display();
            break;
        }
    }
    return 0;
}*/

//4
/*#include <iostream>
#include <cmath>


using namespace std;

class Solid{
    private:
        float volume;
    public:
        int vol(int i){
            volume=pow(i,3);
            return volume;
        }
        float vol(float i){
            volume=(4.0/3.0)*3.14*pow(i,3);
            return volume;
        }
        float vol(float i,float j){
            volume=3.14*i*i*j;
            return volume;
        }
        float vol(float i,float j,float k){
            volume=i*j*k;
            return volume;
        }
        void display(){
            cout<<"Volume is: "<<volume<<"\n"<<endl;
        }
};

int main(){
    Solid s;
    int a;
    float b,c,d;
    cout<<"Enter the side of cube: ";
    cin>>a;
    s.vol(a);
    s.display();
    cout<<"Enter the radius of sphere: ";
    cin>>b;
    s.vol(b);
    s.display();
    cout<<"Enter the radius of cylinder: ";
    cin>>c;
    cout<<"Enter the height of cylinder: ";
    cin>>d;
    s.vol(c,d);
    s.display();
    cout<<"Enter the length of cuboid: ";
    cin>>a;
    cout<<"Enter the breadth of cuboid: ";
    cin>>b;
    cout<<"Enter the height of cuboid: ";
    cin>>c;
    s.vol(a,b,c);
    s.display();
    return 0;
}*/

//5
/*#include <iostream>
#include <conio.h>


using namespace std;
class TollBooth{
    private:
        unsigned int totalCars;
        double totalAmount;
    public:
        TollBooth(){
            totalCars=0;
            totalAmount=0;
        }
        void payingCar(){
            totalCars=totalCars+1;
            totalAmount=totalAmount+0.5;
        }
        void nopayCar(){
            totalCars++;
        }
        void escape(){
            cout<<"Pressed Escape"<<endl;
        }
        void display(){
            printf("Total Cars : %d\n",totalCars);
            printf("Total Amount : %f",totalAmount);
            // cout<<endl;
            // cout<<"Total cars: "<<totalCars<<endl;
            // cout<<"Total money: "<<totalAmount<<endl;
        }
};

int main(){
    cout<<"Enter p for paying cars and n for non paying cars and esc to display the output and exit"<<endl;
    char inp;
    TollBooth a;
    while(true){
        inp=getch();
        cout<<inp<<endl;
        if(inp=='p'){
            a.payingCar();
        }
        else if(inp=='n'){
            a.nopayCar();
        }
        else if(int(inp)==27){
            cout<<"Exiting"<<endl;
            a.display();
            break;
        }
    }
}*/

//6
/*#include <iostream>

using namespace std;

class Time{
    private:
        int hours;
        int minutes;
        int seconds;
    public:
        Time(){
            hours=0;
            minutes=0;
            seconds=0;
        }
        Time(int h,int m,int s){
            hours=h;
            minutes=m;
            seconds=s;
        }
        void display(){
            cout<<hours<<":"<<minutes<<":"<<seconds<<endl;
        }
        void add(Time t1,Time t2){
            seconds=t1.seconds+t2.seconds;
            minutes=t1.minutes+t2.minutes;
            hours=t1.hours+t2.hours;
            if(seconds>=60){
                seconds-=60;
                minutes++;
            }
            if(minutes>=60){
                minutes-=60;
                hours++;
            }
        }
};

int main(){
    cout<<"Enter time 1 : "<<endl;
    int h1,m1,s1,h2,m2,s2;
    cout<<"Enter hours : ";
    cin>>h1;
    cout<<"Enter minutes : ";
    cin>>m1;
    cout<<"Enter seconds : ";
    cin>>s1;
    cout<<endl;
    cout<<"Enter time 2 : "<<endl;
    cout<<"Enter hours : ";
    cin>>h2;
    cout<<"Enter minutes : ";
    cin>>m2;
    cout<<"Enter seconds : ";
    cin>>s2;
    Time t1(h1,m1,s1);
    Time t2(h2,m2,s2);
    Time t3;
    t3.add(t1,t2);
    t3.display();
}*/

//7
/*#include <iostream>

using namespace std;

class Account{
    public:
        string name;
        int acc_no;
        string acc_type;
        int balance;
    public:
        Account(){
            name="Default";
            acc_no=0000;
            acc_type="Savings";
            balance=0;
        }
        Account(string n,int a,string t,int b){
            name=n;
            acc_no=a;
            acc_type=t;
            balance=b;
        }
        
        string getName(){
            return name;
        }
        int getAccNo(){
            return acc_no;
        }
        string getAccType(){
            return acc_type;
        }
        int getBalance(){
            return balance;
        }
        void deposit(int amount){
            balance+=amount;
            cout<<"Amount deposited successfully!"<<endl;
            cout<<"Balance: "<<balance<<endl;
        }
        void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"Account Number: "<<acc_no<<endl;
            cout<<"Account Type: "<<acc_type<<endl;
            cout<<"Balance: "<<balance<<endl;
        }
};

class sav_acct:public Account{
    public:
        int interest;
        float rate;
    public:
        sav_acct(){
            interest=0;
            rate=0.0;
            acc_type="Savings";
        }
        void calc_interest(){
            interest=balance*rate;
            cout<<"Interest: "<<interest<<endl;
            balance+=interest;
            cout<<"Balance: "<<balance<<endl;
        }
        void withdraw(int amount){
            if(amount>balance){
                cout<<"Insufficient balance!"<<endl;
                cout<<"Current Balance: "<<balance<<endl;
            }else{
                balance-=amount;
                cout<<"Amount withdrawn successfully"<<endl;
                cout<<"Balance: "<<balance<<endl;
            }
        }
};

class cur_acct:public Account{
    public:
        cur_acct(){
            acc_type="Current";
        }
        void check_balance(){
            if(balance<1000){
                cout<<"Balance is less than 1000!\n"<<endl;
                if(balance<500){
                    cout<<"Penality of "<<balance<<" is imposed."<<endl;
                    balance=0;
                }
                else{
                    cout<<"Penality of 500 is imposed."<<endl;
                    balance-=500;
                }
                cout<<"Balance: "<<balance<<endl;
            }
        }
};

int main(){
    sav_acct s;
    cur_acct c;
    s.name="Prashanth";
    s.acc_no=1234;
    s.balance=1000;
    s.rate=0.05;
    s.display();
    s.calc_interest();
    s.withdraw(500);
    s.display();
    cout<<"\n\n";
    c.name="Alpha_NG";
    c.acc_no=5678;
    c.balance=500;
    c.display();
    c.check_balance();
    c.display();
    

    return 0;
}*/
