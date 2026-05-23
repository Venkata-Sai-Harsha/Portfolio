#include <bits/stdc++.h>
using namespace std;

int printnaturalnumbers(int n,int i){
    if (n == 0 || i > n) {
        return 0;
    } else {
        cout << i << " ";
        printnaturalnumbers(n, i + 1);
    }
}
int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Natural numbers from 1 to " << n << ": ";
    printnaturalnumbers(n,1);
}