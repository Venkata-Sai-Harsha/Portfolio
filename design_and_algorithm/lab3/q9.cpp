#include <iostream>
#include <vector>

using namespace std;

int longestPalindromeSubseq(string str) {
    int n = str.length();

    // Create a 2D table to store lengths of longest palindromic subsequences
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Every character is a palindrome of length 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Build the table in a bottom-up manner
    for (int cl = 2; cl <= n; cl++) {
        for (int i = 0; i < n - cl + 1; i++) {
            int j = i + cl - 1;
            if (str[i] == str[j] && cl == 2) {
                dp[i][j] = 2;
            } else if (str[i] == str[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }

    // Length of the longest palindromic subsequence is stored in dp[0][n-1]
    return dp[0][n - 1];
}

int main() {
    string str;

    cout << "Enter the string: ";
    cin >> str;

    int result = longestPalindromeSubseq(str);

    cout << "Length of the longest palindromic subsequence: " << result << endl;

    return 0;
}

