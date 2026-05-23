#include <bits/stdc++.h>
using namespace std;
int bubbleSortOptimized(int arr[],int n) {
    bool swapped = true; 
    while (swapped) {
        swapped = false; 
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]); 
                swapped = true;
            }
        }
        n--;  
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubbleSortOptimized(arr,n);
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
