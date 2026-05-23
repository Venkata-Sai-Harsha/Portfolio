#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int left, int right, int pivot) {
    int i = left;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    return i;
}

int select(vector<int>& arr, int left, int right, int k) {
    while (left < right) {
        int pivotIndex = left + rand() % (right - left);
        int pivot = arr[pivotIndex];
        int partitionIndex = partition(arr, left, right, pivot);
        if (partitionIndex == k) {
            return arr[partitionIndex];
        } else if (partitionIndex < k) {
            left = partitionIndex + 1;
        } else {
            right = partitionIndex;
        }
    }

    return arr[left];
}

int findMedianOfMedians(vector<int>& arr) {
    int n = arr.size();
    int medianIndex = n / 2;
    return select(arr, 0, n, medianIndex);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int median = findMedianOfMedians(arr);
    cout << "The median of medians is: " << median << endl;
    return 0;
}