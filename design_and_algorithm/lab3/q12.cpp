#include <iostream>
#include <vector>

using namespace std;

bool canPartition(const vector<int>& nums) {
    int totalSum = 0;

    // Calculate the total sum of the set
    for (int num : nums) {
        totalSum += num;
    }

    // If the total sum is odd, it cannot be partitioned into two equal subsets
    if (totalSum % 2 != 0) {
        return false;
    }

    int targetSum = totalSum / 2;
    int n = nums.size();

    // Create a 2D array to represent the subset sum problem
    vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));

    // Initialization: It is always possible to have an empty subset with sum 0
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Dynamic programming to fill the 2D array
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= targetSum; ++j) {
            // If the current element is greater than the target sum, skip it
            if (nums[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Check whether it is possible to achieve the target sum
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    // The result is stored in the bottom-right cell of the 2D array
    return dp[n][targetSum];
}

int main() {
    // Example usage:
    vector<int> nums = {1, 5, 11, 5};

    if (canPartition(nums)) {
        cout << "The set can be divided into two subsets with equal sum." << endl;
    } else {
        cout << "The set cannot be divided into two subsets with equal sum." << endl;
    }

    return 0;
}