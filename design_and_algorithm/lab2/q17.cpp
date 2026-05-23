#include <bits/stdc++.h>
using namespace std;

int isSorted(vector<int>& a, int i, int n) {
    if (i == n) {
        return 1;
    }
    if (a[i] <= a[i + 1]) {
        return isSorted(a, i + 1, n);
    } else {
        return 0;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int& x : a) {
        cin >> x;
    }
    int x = isSorted(a, 0, n - 1);
    if (x == 1) {
        cout << "Array is sorted" << std::endl;
    } else {
        cout << "Array is not sorted" << std::endl;
    }
    return 0;
}