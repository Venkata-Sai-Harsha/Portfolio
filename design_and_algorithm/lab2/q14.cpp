#include <iostream>
using namespace std;

void printArray(int arr[], int n, int index) {
    if (index >= n) {
        return;
    }
    cout << arr[index] << " ";
    printArray(arr, n, index + 1);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "The array is: ";
    printArray(arr, n, 0);
    return 0;
}
