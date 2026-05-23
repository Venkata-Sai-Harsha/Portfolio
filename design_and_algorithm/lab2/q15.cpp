#include <bits/stdc++.h>
using namespace std;

int printarrayrevese(int arr[], int n){
    if(n==0){
        return 0;
    }
    cout << arr[n-1] << " ";
    return printarrayrevese(arr, n-1);
}
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "The elements of the array in reverse order are: ";
    printarrayrevese(arr,n);
}