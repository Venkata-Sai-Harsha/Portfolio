#include <iostream>
#include <vector>

int maxLengthIncreasingSubsequence(const std::vector<int>& A) {
    int n = A.size();
    std::vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    // Find the maximum value in dp
    int maxLength = 0;
    for (int i = 0; i < n; ++i) {
        maxLength = std::max(maxLength, dp[i]);
    }

    return maxLength;
}

int main() {
    // Example usage:
    std::vector<int> sequence = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    
    int result = maxLengthIncreasingSubsequence(sequence);
    std::cout << "Maximum length of increasing subsequence: " << result << std::endl;

    return 0;
}