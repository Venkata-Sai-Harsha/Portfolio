#include <bits/stdc++.h>
using namespace std;

int hcf(int a, int b){
    if(b==0){
        return a;
    }
    return hcf(b, a%b);
}
int main(){
    int a,b;
    cout << "Enter two numbers a & b: ";
    cin >> a >> b;
    cout << "HCF of " << a << " and " << b << " is: ";
    cout << hcf(a,b);
}