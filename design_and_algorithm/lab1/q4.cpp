#include <bits/stdc++.h>
using namespace std;

int binarysearch(vector<int> arr, int n, int k) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2; 
        if (arr[mid] == k) {
            return mid;
        } 
        else if (arr[mid] < k) {
            l = mid + 1;
        } 
        else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int r = binarysearch(v, n, k);
    if (r == -1) {
        cout << "not found";
    } else {
        cout << "found at index " << r;
    }
}