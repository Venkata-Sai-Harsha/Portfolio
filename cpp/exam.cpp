/*#include <bits/stdc++.h>
using namespace std;
void lcs(string s1,string s2){
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << "length of lcs is: ";
    cout << dp[m][n] << endl;
    int it=dp[m][n];
    char s3[it+1];
    s3[it] = '\0';
    int i=m;
    int j=n;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s3[it-1]=s1[i-1];
            i--;
            j--;
            it--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout << "lcs is: " << s3 << endl;
}

int main(){
    string s1;
    string s2;
    int n;
    cout << "enter the size: ";
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "enter the first string: ";
        cin >> s1;
        cout << "enter the second string: ";
        cin >> s2;
        lcs(s1,s2);
    }
}*/

/*#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v,int l,int r){
    int pivot=v[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(v[j]<pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[r]);
    return i+1;
}

void quicksort(vector<int> &v,int l,int r){
    if(l<r){
        int pi=partition(v,l,r);
        quicksort(v,l,pi-1);
        quicksort(v,pi+1,r);
    }
}

int main(){
    int n;
    cout << "enter the size: ";
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cout << "enter the elements: ";
        int a;
        cin >> a;
        v.push_back(a);
    }
    quicksort(v,0,n-1);
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
}*/

/*#include <bits/stdc++.h>
using namespace std;

void lis(vector<int> &v,int n){
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i]>v[j] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(dp[i]>max){
            max=dp[i];
        }
    }
    cout << "length of lis is: " << max << endl;
    int it=max;
    int s[it+1];
    int i=n;
    while(i>=0){
        if(dp[i]==it){
            s[it-1]=v[i];
            it--;
        }
        i--;
    }
    cout << "lis is: ";
    for(int i=0;i<max;i++){
        cout << s[i] << " ";
    }
}

int main(){
    vector<int> v;
    int n;
    cout << "enter the size: ";
    cin >> n;
    cout << "enter the elements: ";
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    lis(v,n);
}*/

/*#include <bits/stdc++.h>
using namespace std;

void kanpsack(vector<int>& val,vector<int>& wt,int w,int n){
    vector<vector<int>> dp(n+1,vector<int>(w+1));
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=w;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(wt[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout << dp[n][w] << endl;
}

int main(){
    int n;
    cout << "enter the size: ";
    cin >> n;
    vector<int> val,wt;
    cout << "enter the value: ";
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        val.push_back(a);
    }
    cout << "enter the weight: ";
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        wt.push_back(a);
    }
    int w;
    cout << "enter the capacity: ";
    cin >> w;
    kanpsack(val,wt,w,n);
}*/


/*#include <iostream>
using namespace std;

void fibonacci(int n) {
    int f[n];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    for(int i=0;i<n;i++){
        cout << f[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    fibonacci(n);
    return 0;
}*/

/*#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>a,pair<int,int>b){
    double c=(double)a.first/a.second;
    double d=(double)b.first/b.second;
    return c>d;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> k(n);
    for(int i=0;i<n;i++){
        cin >> k[i].first >> k[i].second;
    }
    int w,val=0;
    cin >> w;
    sort(k.begin(),k.end(),compare);
    for(int i=0;i<n;i++){
        if(w>=k[i].second){
            val=val+k[i].first;
            w=w-k[i].second;
        }
        else{
            val=val+((w*k[i].first)/k[i].second);
            break;
        }
    }
    cout << val;
}*/

/*#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end(),compare);
    int j=0;
    cout << "(" << v[j].first << "," << v[j].second << ")";
    for(int i=1;i<n;i++){
        if(v[i].first>=v[j].second){
            j=i;
            cout << "(" << v[j].first << "," << v[j].second << ")";
        }
    }
    return 0;
}*/


#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& v,int l,int r){
    int piviot=v[r];
    int i=l-1;
    for(int j=l;j<r-1;j++){
        if(v[j]<=piviot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[r]);
    return i+1;
}

void quicksort(vector<int>& v,int l, int r){
    if(l<r){
        int pi=partition(v,l,r);
        quicksort(v,l,pi-1);
        quicksort(v,pi+1,r);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    quicksort(v,0,n-1);
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}