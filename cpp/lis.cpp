#include <iostream>
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
}