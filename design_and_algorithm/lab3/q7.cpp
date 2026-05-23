#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int minimizeMultiplicationSum(vector<int>& numbers) {
    int sum = 0;
    int n = numbers.size();

    while (n > 1) {
        int minMul = INT_MAX;
        int minIndex = -1;

        for (int i = 0; i < n - 1; i++) {
            int mul = numbers[i] * numbers[i + 1];
            if (mul < minMul) {
                minMul = mul;
                minIndex = i;
            }
        }

        // Add the minimum multiplication to the sum
        sum += minMul;

        // Put back the sum modulo 100
        int newNumber = (numbers[minIndex] + numbers[minIndex + 1]) % 100;

        // Erase the two numbers used in the multiplication
        numbers.erase(numbers.begin() + minIndex, numbers.begin() + minIndex + 2);

        // Insert the new number
        numbers.insert(numbers.begin() + minIndex, newNumber);

        // Reduce the size of the array
        n = numbers.size();
    }

    return sum;
}

int main() {
    int n;

    cout << "Enter the number of integers: ";
    cin >> n;

    vector<int> numbers(n);

    cout << "Enter the integers: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int result = minimizeMultiplicationSum(numbers);

    cout << "Minimum sum of multiplication: " << result << endl;

    return 0;
}
