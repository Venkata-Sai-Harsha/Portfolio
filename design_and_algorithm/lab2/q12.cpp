#include <bits/stdc++.h>
using namespace std;

int printnaturalnumbersreverse(int n){
    if(n<=0){
        return 0;
    }
    cout << n << " ";
    return printnaturalnumbersreverse(n-1);
}
int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "The natural numbers from " << n << " to 1 are: ";
    printnaturalnumbersreverse(n);
}