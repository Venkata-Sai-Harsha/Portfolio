#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& arr, int low, int mid, int high, vector<pair<int, int>>& inversionPairs) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary arrays
    vector<int> left(n1), right(n2);

    // Copy data to temporary arrays left[] and right[]
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[low..high]
    long long inversionCount = 0;
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            // If an element from the right subarray is smaller,
            // then there are n1 - i inversions.
            inversionCount += n1 - i;

            // Store the pairs involved in inversion
            for (int p = 0; p < n1; p++) {
                inversionPairs.push_back({left[p], right[j - 1]});
            }
        }
    }

    // Copy the remaining elements of left[], if there are any
    while (i < n1) {
        arr[k++] = left[i++];
    }

    // Copy the remaining elements of right[], if there are any
    while (j < n2) {
        arr[k++] = right[j++];
    }

    return inversionCount;
}

long long mergeSortAndCount(vector<int>& arr, int low, int high, vector<pair<int, int>>& inversionPairs) {
    long long inversionCount = 0;
    if (low < high) {
        int mid = low + (high - low) / 2;

        // Divide and conquer
        inversionCount += mergeSortAndCount(arr, low, mid, inversionPairs);
        inversionCount += mergeSortAndCount(arr, mid + 1, high, inversionPairs);

        // Merge the sorted halves and count inversions
        inversionCount += mergeAndCount(arr, low, mid, high, inversionPairs);
    }
    return inversionCount;
}

long long countInversions(vector<int>& arr, vector<pair<int, int>>& inversionPairs) {
    return mergeSortAndCount(arr, 0, arr.size() - 1, inversionPairs);
}

int main() {
    vector<int> arr = {3, 1, 5, 2};
    vector<pair<int, int>> inversionPairs;

    long long inversions = countInversions(arr, inversionPairs);

    cout << "The number of inversions in the array: " << inversions << endl;

    cout << "Pairs involved in inversions:" << endl;
    for (const auto& pair : inversionPairs) {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }

    return 0;
}
