#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void printOptimalParenthesis(vector<vector<int>>& bracket, int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }

    cout << "(";

    printOptimalParenthesis(bracket, i, bracket[i][j]);
    printOptimalParenthesis(bracket, bracket[i][j] + 1, j);

    cout << ")";
}

void matrixChainOrder(vector<int>& dimensions) {
    int n = dimensions.size() - 1; // Number of matrices

    // Initialize the cost and bracket matrices
    vector<vector<int>> cost(n, vector<int>(n, 0));
    vector<vector<int>> bracket(n, vector<int>(n, 0));

    // Build the cost matrix bottom-up
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int tempCost = cost[i][k] + cost[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];

                if (tempCost < cost[i][j]) {
                    cost[i][j] = tempCost;
                    bracket[i][j] = k;
                }
            }
        }
    }

    cout << "Optimal Parenthesization: ";
    printOptimalParenthesis(bracket, 0, n - 1);
    cout << endl;

    cout << "Minimum number of multiplications: " << cost[0][n - 1] << endl;
}

int main() {
    int n;

    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<int> dimensions(n + 1);

    cout << "Enter the dimensions of matrices: ";
    for (int i = 0; i <= n; i++) {
        cin >> dimensions[i];
    }

    matrixChainOrder(dimensions);

    return 0;
}

