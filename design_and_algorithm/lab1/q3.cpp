#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n;
    cin >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i=0;i<n;i++){
        if(v[i]==k){
            cout << "found at index " << i;
            return 0;
        }
    }
}