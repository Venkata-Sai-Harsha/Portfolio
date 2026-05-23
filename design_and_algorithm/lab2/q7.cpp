#include <bits/stdc++.h>
using namespace std;

int sumofnaturalnumbers(int n){
    if(n==1){
        return 1;
    }
    return n + sumofnaturalnumbers(n-1);
}
int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Sum of first " << n << " natural numbers: ";
    cout << sumofnaturalnumbers(n);
}