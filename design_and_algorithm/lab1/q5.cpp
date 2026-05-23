#include <bits/stdc++.h>
using namespace std;

int findlargest(int arr[],int n,int largest){
    if(n==0){
        return largest;
    }
    if(arr[n]>largest){
        largest = arr[n];
    }
    return findlargest(arr,n-1,largest);
}

int findsmallest(int arr[],int n,int smallest){
    if(n==0){
        return smallest;
    }
    if(arr[n]<smallest){
        smallest = arr[n];
    }
    return findsmallest(arr,n-1,smallest);
}


int main(){
    int arr[] = {4,2,9,1,8,5,2,7,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(n<3){
        cout << "Array doesn't have enough elements" << endl;
    }
    int largest = findlargest(arr,n-1,arr[n-1]);
    int smallest = findsmallest(arr,n-1,arr[n-1]);
    int middle = 0;
    for(int i=0;i<n;i++){
        if(arr[i]!=largest && arr[i]!=smallest){
            middle = arr[i];
            break;
        }
    }
    cout << "The element that is neither largest nor the smallest is: " << middle << endl;
    return 0;
}