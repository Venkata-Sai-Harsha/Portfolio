#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> LIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> pre(n, -1);
    int max_len = 0;
    int max_idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            max_idx = i;
        }
    }
cout << "Length of LIS is: " << max_len << endl;
    vector<int> res;
    while (max_idx != -1) {
        res.push_back(nums[max_idx]);
        max_idx = pre[max_idx];
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60};
    vector<int> res = LIS(nums);
    cout << "The LIS is: ";
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
