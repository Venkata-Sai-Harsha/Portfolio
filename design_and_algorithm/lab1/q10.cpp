#include <iostream>
#include <vector>

int main() {
    int n;
    // Input size of arrays
    std::cout << "Enter the size of arrays: ";
    std::cin >> n;

    std::vector<int> A(n), B(n), C(2 * n);

    // Input elements of array A
    std::cout << "Enter elements of array A: ";
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    // Input elements of array B
    std::cout << "Enter elements of array B: ";
    for (int i = 0; i < n; i++) {
        std::cin >> B[i];
    }

    int i = 0, j = 0, k = 0;

    while (i < n && j < n) {
        if (A[i] < B[j]) {
            C[k] = A[i];
            k++;
            i++;
        } 
        else {
            C[k] = B[j];
            k++;
            j++;
        }
    }

    while (i < n) {
        C[k] = A[i];
        k++;
        i++;
    }

    while (j < n) {
        C[k] = B[j];
        k++;
        j++;
    }

    // Display merged array C
    std::cout << "Merged array C: ";
    for (int i = 0; i < 2 * n; i++) 
    {
        std::cout << C[i] << " ";
    }

    return 0;
}