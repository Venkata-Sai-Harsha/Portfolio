/*fibinocci sequence in dynamic programming*/
/*#include <iostream>
using namespace std;

int fibonacci(int n) {
    int f[n+2];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    return 0;
}*/

/*0/1 knapsack in dynamic programming*/
/*#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	vector<vector<int> > K(n + 1, vector<int>(W + 1));
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1]+ K[i - 1][w - wt[i - 1]],K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}

int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);

	cout << knapSack(W, wt, val, n);

	return 0;
}*/

/*longest common subsequence in dynamic programming*/
/*#include <bits/stdc++.h>
using namespace std;

void lcsAlgo(char *S1, char *S2, int m, int n) {
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
cout << "Length of LCS is: " << dp[m][n] << endl;

    int index = dp[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (S1[i - 1] == S2[j - 1]) {
            lcsAlgo[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << lcsAlgo << "\n";
}

int main() {
    char S1[] = "abcabcaa";
    char S2[] = "acbacba";
    int m = strlen(S1);
    int n = strlen(S2);
    lcsAlgo(S1, S2, m, n);
    return 0;
}*/



/*longest increasing subsequence in dynamic programming*/
/*#include <bits/stdc++.h>
using namespace std;

int lis(int arr[], int n) {
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++){
            if (arr[i] > arr[j] && lis[j] + 1 > lis[i])
                lis[i] = lis[j] + 1;
        }
    }
    return *max_element(lis, lis + n);
}

int main() {
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
	int n = 9;
	cout << lis(arr, n);
	return 0;
}*/


/* 0/1 kanapsack problem in dynamic programming*/
/*#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n){
	int i, j;
	vector<vector<int> > K(n + 1, vector<int>(W + 1));
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= W; j++) {
			if (i == 0 || j == 0)
				K[i][j] = 0;
			else if (wt[i - 1] <= j)
				K[i][j] = max(K[i - 1][j],val[i-1]+ K[i - 1][j - wt[i-1]]);
			else
				K[i][j] = K[i - 1][j];
		}
	}
	return K[n][W];
}

int main()
{
	int val[] = { 3,4,5,6 };
	int wt[] = { 2,3,4,5 };
	int W = 8;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n);
	return 0;
}*/


/*#include <bits/stdc++.h>
using namespace std;

int listar(vector<int>& arr,int n){
    vector<int> lis(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && lis[j]+1>lis[i]){
                lis[i]=lis[j]+1;
            }
        }
    }
    return *max_element(lis.begin(),lis.end());
}
int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> array;
    cout << "Enter the elements of array: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        array.push_back(x);
    }
    cout << "Length of longest increasing subsequence is: " << listar(array,n);
}*/


/*fractional knapscak in greedy algorithm*/
/*#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>a,pair<int,int>b){
    double c=(double)a.first/a.second;
    double d=(double)b.first/b.second;
    return c>d;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> ksack(n);
    for(int i=0;i<n;i++){
        cin>>ksack[i].first>>ksack[i].second;
    }
    int w,val=0;
    cin>>w;
    sort(ksack.begin(),ksack.end(),compare);
    for(int i=0;i<n;i++){
        if(w>=ksack[i].second){
            val=val+ksack[i].first;
            w=w-ksack[i].second;
        }
        else{
            val=val+(double(w*ksack[i].first))/ksack[i].second;
            cout<<val;
            break;
        }
    }
    return 0;
}*/

/*#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}
int main(){
    int n;
    cin>>n;
    vector <pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),compare);
    int j=0;
    cout<<"("<<v[j].first<<","<<v[j].second<<")";
    for( int i=1;i<n;i++){
        if(v[i].first>=v[j].second){
            j=i;
            cout<<"("<<v[j].first<<","<<v[j].second<<")";
        }
    }
    return 0;
}*/

#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[i]);
    return i;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    quicksort(v,0,n-1);
    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
