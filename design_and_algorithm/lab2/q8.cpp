#include <bits/stdc++.h>
using namespace std;

int productofnaturalnumbers(int n){
    if(n==1){
        return 1;
    }
    return n * productofnaturalnumbers(n-1);
}
int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Product of natural numbers from 1 to " << n << " is: ";
    cout << productofnaturalnumbers(n);
}