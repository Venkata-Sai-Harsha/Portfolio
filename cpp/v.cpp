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
    int ar1[] = {1, 2, 3, 6};
    int ar2[] = {4, 6, 8, 10};
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is "<< getMedian(ar1, ar2, n1);
    else
        cout << "Doesn't work for arrays " << "of unequal size";
    return 0;
}