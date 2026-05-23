#include<iostream>
using namespace std;
int median(int arr[], int n)
{
    if (n % 2 == 0)
        return (arr[n / 2] + arr[n / 2 - 1]) / 2;
    else
        return arr[n / 2];
}
int getMedian(int array1[], int array2[], int n)
{
    if (n <= 0)
        return -1;
    if (n == 1)
        return (array1[0] + array2[0]) / 2;
    if (n == 2)
        return (max(array1[0], array2[0]) + min(array1[1], array2[1])) / 2;
    int m1 = median(array1, n); 
    int m2 = median(array2, n); 
    if (m1 == m2)
        return m1;
    if (m1 < m2)
    {
        if (n % 2 == 0){
            return getMedian(array1 + n / 2 - 1, array2, n - n / 2 + 1);
        }
        else{
            return getMedian(array1 + n / 2, array2, n - n / 2);
        }
    }
    else{
        if (n % 2 == 0){
            return getMedian(array2 + n / 2 - 1, array1, n - n / 2 + 1);
        }
        else{
            return getMedian(array2 + n / 2, array1, n - n / 2);
        }
    }
}
int main()
{
    int n1,n2;
    cout << "Enter the size of the array1: ";
    cin >> n1;
    int array1[n1];
    cout << "Enter the elements of the array1: ";
    for (int i = 0; i < n1; i++) 
    {
        cin >> array1[i];
    }
    cout << "Enter the size of the array2: ";
    cin >> n2;
    int array2[n2];
    cout << "Enter the elements of the array2: ";
    for (int j = 0; j < n2; j++)
    {
        cin >> array2[j];
    }
    if (n1 == n2)
        cout << "Median is " << getMedian(array1, array2, n1);
    else
        cout << "Doesn't work for arrays " << "of unequal size";
    return 0;
}

/*#include <iostream>
using namespace std;

int main() {
    int n1,n2;
    cout << "Enter the size of the array1: ";
    cin >> n1;
    int array1[n1];
    cout << "Enter the elements of the array1: ";
    for (int i = 0; i < n1; i++) {
        cin >> array1[i];
    }
    cout << "Enter the size of the array1: ";
    cin >> n2;
    int array2[n2];
    cout << "Enter the elements of the array1: ";
    for (int j = 0; j < n2; j++) {
        cin >> array2[i];
    }
    return 0;
}*/
