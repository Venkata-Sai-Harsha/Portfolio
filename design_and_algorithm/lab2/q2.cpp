#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
int main(){
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    selectionSort(arr);
    cout << "The sorted array is: ";
    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
}