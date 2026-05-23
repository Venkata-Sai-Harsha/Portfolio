/*#include <iostream>
using namespace std;

// function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// function to perform quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// main function
int main() {
    int arr[] = {3, 8, 5, 4, 1, 9, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    // print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}*/



// Quick sort in C++

/*#include <iostream>
using namespace std;
 
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
      cout << array[i] << " ";
    cout << endl;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high-1; j++) {
      if (array[j] <= pivot) {
        i++;
        swap(&array[i], &array[j]);
      }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
      int pi = partition(array, low, high);
      quickSort(array, low, pi - 1);
      quickSort(array, pi + 1, high);
    }
}

int main() {
    int data[] = {8, 7, 6, 1, 0, 9, 2};
    int n = sizeof(data) / sizeof(data[0]);  
    cout << "Unsorted Array: \n";
    printArray(data, n);
    quickSort(data, 0, n - 1); 
    cout << "Sorted array in ascending order: \n";
    printArray(data, n);
}*/

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void printVector(vector<int> &array) {
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
}

int partition(vector<int> &array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high-1; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void quickSort(vector<int> &array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> data;
    cout << "Enter the elements: ";
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        data.push_back(x);
    }
    cout << "Unsorted Vector: \n";
    printVector(data);
    quickSort(data, 0,n - 1);
    cout << "Sorted vector in ascending order: \n";
    printVector(data);
}