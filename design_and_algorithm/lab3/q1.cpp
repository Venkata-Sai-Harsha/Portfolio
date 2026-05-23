#include <iostream>
using namespace std;

int maxSubarrayLength(int arr[], int n) {
    int maxSum = arr[0];
    int currentSum = arr[0];
    int maxLength = 1;
    int currentLength = 1;

    for (int i = 1; i < n; i++) {
        if (currentSum + arr[i] > arr[i]) {
            currentSum += arr[i];
            currentLength++;
        } else {
            currentSum = arr[i];
            currentLength = 1;
        }
        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxLength = currentLength;
        }
    }
    return maxLength;
}

int main() {
    int arr[] = {1, -2, 3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxLength = maxSubarrayLength(arr, n);
    cout << "Length of the subarray with maximum sum: " << maxLength << endl;
    return 0;
}