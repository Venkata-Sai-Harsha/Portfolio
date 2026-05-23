#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[]={2,7,7,11,24,24,29,36,36};
    int n=sizeof(arr)/sizeof(arr[0]);
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    cout << "Unique elements in the array b[]: {";
    for(auto i=s.begin();i!=s.end();i++){
        cout << *i << ", ";
    }
    cout << "}" << endl;
}