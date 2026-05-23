/*#include <bits/stdc++.h>
using namespace std;

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,int right);
int mergeSort(int arr[], int array_size)
{
	int temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}
int _mergeSort(int arr[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left) {
		mid = (right + left) / 2;
		inv_count += _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);
		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}
int merge(int arr[], int temp[], int left, int mid,int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid - i);
		}
	}
	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

int main()
{
	int arr[] = { 1, 20, 6, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int ans = mergeSort(arr, n);
	cout << " Number of inversions are " << ans;
	return 0;
}


#include<bits/stdc++.h>
#define ROW 4
#define COL 4
using namespace std;
void search(int mat[ROW][COL], int fromRow, int toRow,int fromCol, int toCol, int key)
{
    int i = fromRow + (toRow-fromRow )/2;
    int j = fromCol + (toCol-fromCol )/2;
    if (mat[i][j] == key) 
        cout<<"Found "<< key << " at "<< i <<" " << j<<endl;
    else
    {
        if (i != toRow || j != fromCol)
            search(mat, fromRow, i, j, toCol, key);
        if (fromRow == toRow && fromCol + 1 == toCol)
            if (mat[fromRow][toCol] == key)
                cout<<"Found "<< key<< " at "<< fromRow << " " << toCol<<endl;
        if (mat[i][j] < key)
        {
            if (i + 1 <= toRow)
                search(mat, i + 1, toRow, fromCol, toCol, key);
        }
        else
        {
            if (j - 1 >= fromCol)
                search(mat, fromRow, toRow, fromCol, j - 1, key);
        }
    }
}

 

int main()
{
    int mat[ROW][COL] ;
    cout<<"enter key"<<endl;
    int key;
    cin>>key;
    cout <<"enter matrix"<<endl;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cin>>mat[i][j];
        }
    }
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            search(mat, 0, ROW - 1, 0, COL - 1, mat[i][j]);
        }
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

void merge(string Arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    string L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = Arr[start + i];
    for (int i = 0; i < n2; i++)
        R[i] = Arr[mid + 1 + i];
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            Arr[k] = L[i];
            i++;
        } else {
            Arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        Arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        Arr[k] = R[j];
        j++;
        k++;
    }
}

void sortStrings(string Arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        sortStrings(Arr, start, mid);
        sortStrings(Arr, mid + 1, end);
        merge(Arr, start, mid, end);
    }
}
void printArray(string arr[], int size) {
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    string Arr[] = {"elderberry" ,"apple", "date","cherry", "banana"};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    sortStrings(Arr, 0, n - 1);

    cout << "Sorted array: \n";
    printArray(Arr,n);
    return 0;
}*/


/*#include <bits/stdc++.h>
using namespace std;

void merge(vector<string> &Arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    vector<string> L(n1), R(n2);
    for (int i = 0; i < n1; i++){
        L[i] = Arr[start + i];
    }
    for (int i = 0; i < n2; i++){
        R[i] = Arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            Arr[k] = L[i];
            i++;
        } else {
            Arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        Arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        Arr[k] = R[j];
        j++;
        k++;
    }
}

void sortStrings(vector<string> &Arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        sortStrings(Arr, start, mid);
        sortStrings(Arr, mid + 1, end);
        merge(Arr, start, mid, end);
    }
}
void printArray(vector<string> arr, int size) {
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    vector<string> Arr(n);
    cout << "Enter the strings: ";
    for(int i = 0; i < n; i++){
        cin >> Arr[i];
    }
    sortStrings(Arr, 0, n - 1);

    cout << "Sorted array: \n";
    printArray(Arr,n);
    return 0;
}*/



/*#include <iostream>
#include <algorithm>
using namespace std;

int longest_increasing_subsequence(int arr[], int n) {
    int L[n];
    for (int i = 0; i < n; i++) {
        L[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && L[i] < L[j] + 1) {
                L[i] = L[j] + 1;
            }
        }
    }
    int maximum = 0;
    for (int i = 0; i < n; i++) {
        maximum = max(maximum, L[i]);
    }
    return maximum;
}

int main() {
    int arr[] = {3, 10, 2, 1, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of LIS is " << longest_increasing_subsequence(arr, n);
    return 0;
}*/

/*
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int lis(int arr[], int n) {
  int lis[n];

  lis[0] = 1;

  /*for (int i = 1; i < n; i++) {
    lis[i] = 1;
    for (int j = 0; j < i; j++)
      if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
        lis[i] = lis[j] + 1;
  }

  return *max_element(lis, lis + n);
}
int main() {
	// Your code goes here;
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	int n = 9;
	cout << lis(arr, n);
	return 0;
}
*/

/*#include <bits/stdc++.h>
public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
    ListNode h = new ListNode(0);
    ListNode ans=h;
    while (l1 != null && l2 != null) {
        if (l1.val < l2.val) {
            h.next = l1;
            h = h.next;
            l1 = l1.next;
        } else {
            h.next = l2;
            h = h.next;
            l2 = l2.next;
        }
    }
    if(l1==null){
        h.next=l2;
    }
    if(l2==null){
        h.next=l1;
    } 
    return ans.next;
}
public ListNode mergeKLists(ListNode[] lists) {
    if(lists.length==0){
        return null;
    }
    int interval = 1;
    while(interval<lists.length){
        System.out.println(lists.length);
        for (int i = 0; i + interval< lists.length; i=i+interval*2) {
            lists[i]=mergeTwoLists(lists[i],lists[i+interval]);            
        }
        interval*=2;
    }

    return lists[0];
}
int main() {
    vector<ListNode*> lists;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);
    ListNode* mergedList = mergeKLists(lists);
    while (mergedList != nullptr) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    return 0;
}*/


/*#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++){
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j++){
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    int m,n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;
    cout << "Enter the elements of the matrix: ";
    vector<vector<int>> vect(m,vector<int>(n));
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
		    int x;
			cin >> x;
			vect[i][j]=x;
		}
	}
    cout << "Minimum path sum is: " << minPathSum(vect);
    return 0;
}*/


/*#include <bits/stdc++.h>
using namespace std;

vector<int> beautifulArray(int n) {
    vector<int> a = {1};

    while(a.size() < n){
        vector<int> temp;
        for(int i = 0; i < a.size(); i++){
            if( 2*a[i] - 1 <= n){
                temp.push_back(2*a[i] - 1);
            }
        }
        for(int i = 0; i < a.size(); i++){
            if( 2*a[i] <= n){
                temp.push_back(2*a[i]);
            }
        }
        a = temp;
    }
    return a;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin>>n;
    vector<int> res = beautifulArray(n);
    for(int i=0;i<res.size();i++) {
        cout<<res[i]<<" ";
    }
    return 0;
}*/

/*#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int currmaxsum=nums[0],maxsum=nums[0],currminsum = nums[0],minsum = nums[0];
        for(int i=1;i<n;i++){
            currmaxsum = max(nums[i],currmaxsum+nums[i]);
            maxsum = max(maxsum,currmaxsum);
            currminsum = min(nums[i],currminsum+nums[i]);
            minsum = min(minsum,currminsum);
        }
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(minsum==sum)return maxsum;
        return max(maxsum,sum-minsum);
    }
};

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    Solution s;
    cout << "Maximum sum of a circular subarray is: " << s.maxSubarraySumCircular(nums);
    return 0;
}*/

/*#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums)
    {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }
        int val=solve(0,n-1,nums,dp);
        cout<<val;
        int diff=sum-val;
        if(diff>val)
        {
            return false;
        }
        else
        {
            return true;
        }
        
        
        
    }
    int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i==j)
        {
            return nums[i];
        }
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int choice1=nums[i]+min(solve(i+2,j,nums,dp),solve(i+1,j-1,nums,dp));
        int choice2=nums[j]+min(solve(i+1,j-1,nums,dp),solve(i,j-2,nums,dp));
        dp[i][j]=max(choice1,choice2);
        return dp[i][j];
    }
};

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    Solution s;
    cout << "Predict the winner: " << s.PredictTheWinner(nums);
    return 0;
}*/

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
// int countSubstrings(string s) {
// int count=0;
// vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));

//     for(int i=0;i<dp.size();i++)
//     {
//         dp[i][i]=1;
//         count++;
//         if(i+1<dp.size() && s[i]==s[i+1])
//         {
//             dp[i][i+1]=1;
//             count++;
//         }
//     }
//     for(int j=2;j<dp.size();j++)
//     {
//         for(int i=0;i<=j-2;i++)
//         {
//             if(s[i]==s[j] && dp[i+1][j-1]==1)
//             {
//                 dp[i][j]=1;
//                 count++;
//             }
//         }
//     }
//     return count;
// }
// };

// int main(){
//     string s;
//     cout << "Enter the string: ";
//     cin >> s;
//     Solution sol;
//     cout << "Number of palindromic substrings: " << sol.countSubstrings(s);
//     return 0;
// }
