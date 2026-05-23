#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int pivot=v[0];
    vector<int> low,high;

    for(int i=0;i<n;i++){
        if(v[i]<pivot){
            low.push_back(v[i]);
        }
        else if(v[i]>pivot){
            high.push_back(v[i]);
        }
    }
    cout << "low[]: {";
    for(int i=0;i<low.size();i++){
        cout << low[i] << ", ";
    }
    cout << "}" << endl;

    cout << "high[]: {";
    for(int i=0;i<high.size();i++){
        cout << high[i] << ", ";
    }
    cout << "}" << endl;
    return 0;
}