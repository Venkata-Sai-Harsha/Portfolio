#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sortmatrixbykthexam(vector<vector<int>>& score,int k){
    sort(score.begin(),score.end(),[k](const vector<int>& a,const vector<int>& b){
        return a[k]>b[k];
    });
    return score;
}

int main(){
    int m,n,k;
    cout << "Enter the number of students (m): ";
    cin >> m;
    cout << "Enter the number of exams (n): ";
    cin >> n;

    vector<vector<int>> v(m,vector<int>(n));

    cout << "Enter the matrix score (m x n):" << endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }
    cout << "Enter the value of k(0-based index of the exam to sort by): ";
    cin >> k;
    if(k < 0 || k >= n){
        cout << "Invalid value of k" << endl;
    }
    else{
        vector<vector<int>> sortedmatrix = sortmatrixbykthexam(v,k);
        cout << "Matrix after sorting by the " << k << "th exam: " << endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout << sortedmatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}