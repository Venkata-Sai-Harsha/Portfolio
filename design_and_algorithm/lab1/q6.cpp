#include <bits/stdc++.h>

using namespace std;

void PrimeNum(int sum , int a){
    if(sum%3 != 0)
    {
        cout << a << " is a prime number";
    }
    else{
        cout << a << " is not a prime number";
    }
}
int main(){
    int a;
    cin >> a;
    int sum=0;
    int temp =a;

    while(temp != 0)
    {
        int x =temp%10;
        sum = sum+x;
        temp = temp/10;
    }
    PrimeNum(sum,a);
}