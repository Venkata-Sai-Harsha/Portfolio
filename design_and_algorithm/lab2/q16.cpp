#include <bits/stdc++.h>
using namespace std;

int reversenumber(int n){
    if(n==0){
        return 0;
    }
    cout << n%10;
    return reversenumber(n/10);
}
int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "The reverse of the number is: ";
    reversenumber(n);
}