#include <iostream>
#include <vector>

using namespace std;

int countWaysToScore(int S) {
    // Define the moves available
    vector<int> moves = {3, 5, 10};
    
    // Initialize a vector to store the number of ways for each score
    vector<int> dp(S + 1, 0);
    
    // There is one way to score 0 (no moves)
    dp[0] = 1;

    // Update the dp array for each move
    for (int move : moves) {
        for (int score = move; score <= S; ++score) {
            dp[score] += dp[score - move];
        }
    }

    // The final result is the number of ways to score S
    return dp[S];
}

int main() {
    // Example usage:
    int score = 15;
    
    int ways = countWaysToScore(score);
    cout << "Number of ways to score " << score << " is: " << ways << endl;

    return 0;
}