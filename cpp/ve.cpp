/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int helper(vector<int>&nums, int l, int r)
    {
        if(l==r)
            return nums[l];
        int mid=l +(r-l)/2;

        int lss=helper(nums,l,mid);
        
        int rss=helper(nums,mid+1,r);
		
        int i=mid,j=mid+1,sumL=nums[mid],sumR=nums[mid+1],sum=0;
        while(i>=l)
        {
            sum+=nums[i--];
            if(sum>sumL)
                sumL=sum;
        }
        sum=0;
        while(j<=r)
        {
            sum+=nums[j++];
                if(sum>sumR)
                    sumR=sum;
        }
        int css=sumL+sumR;

        return max(css,max(lss,rss));
    }
    int maxSubArray(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol; 
    cout << sol.maxSubArray(nums) << endl;
    return 0;
}*/


/*#include <bits/stdc++.h>
int max(int a, int b) { return (a > b) ? a : b; }
int max(int a, int b, int c) { return max(max(a, b), c); }
int maxCrossingSum(int arr[], int l, int m, int h)
{
	int sum = 0;
	int left_sum = INT_MIN;
	for (int i = m; i >= l; i--) {
		sum = sum + arr[i];
		if (sum > left_sum)
			left_sum = sum;
	}
	sum = 0;
	int right_sum = INT_MIN;
	for (int i = m; i <= h; i++) {
		sum = sum + arr[i];
		if (sum > right_sum)
			right_sum = sum;
	}
	return max(left_sum + right_sum - arr[m], left_sum, right_sum);
}
int maxSubArraySum(int arr[], int l, int h)
{
	if (l > h)
		return INT_MIN;
	if (l == h)
		return arr[l];
	int m = (l + h) / 2;
	return max(maxSubArraySum(arr, l, m - 1),maxSubArraySum(arr, m + 1, h),maxCrossingSum(arr, l, m, h));
}

int main()
{
	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	int max_sum = maxSubArraySum(arr, 0, n - 1);
	printf("Maximum contiguous sum is %d\n", max_sum);
	return 0;
}*/


#include <bits/stdc++.h>
using namespace std;

int maxCrossingSum(int a[], int low, int mid, int high) {
    int left_sum = INT_MIN, sum = 0;
    for (int i = mid; i >= low; i--) {
        sum = sum + a[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum = sum + a[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return left_sum + right_sum;
}

int maxSubArraySum(int a[], int low, int high) {
    if (low == high)
        return a[low];
    int mid = (low + high) / 2;
    int left_sum = maxSubArraySum(a, low, mid);
    int right_sum = maxSubArraySum(a, mid + 1, high);
    int cross_sum = maxCrossingSum(a, low, mid, high);
    if (left_sum >= right_sum && left_sum >= cross_sum)
        return left_sum;
    if (right_sum >= left_sum && right_sum >= cross_sum)
        return right_sum;
    else
        return cross_sum;
}

int main() {
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, 0, n - 1);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}
