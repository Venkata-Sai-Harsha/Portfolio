#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A function to find the maximum length of strings
int findMaxLength(vector<string>& arr) {
    int maxLength = arr[0].length();
    for (const string& s : arr) {
        if (s.length() > maxLength) {
            maxLength = s.length();
        }
    }
    return maxLength;
}

// A modified counting sort to sort the strings based on a specific character position
void countingSortByChar(vector<string>& arr, int exp) {
    const int radix = 256; // Assuming ASCII characters

    int n = arr.size();
    vector<string> output(n);
    vector<int> count(radix, 0);

    for (int i = 0; i < n; i++) {
        int index = (exp < arr[i].length()) ? arr[i][arr[i].length() - exp - 1] : 0;
        count[index]++;
    }

    for (int i = 1; i < radix; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (exp < arr[i].length()) ? arr[i][arr[i].length() - exp - 1] : 0;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort for strings
void radixSortStrings(vector<string>& arr) {
    int maxLength = findMaxLength(arr);

    for (int exp = maxLength - 1; exp >= 0; exp--) {
        countingSortByChar(arr, exp);
    }
}

int main() {
    vector<string> arr = {"apple", "banana", "grape", "kiwi", "orange", "pear"};
    
    cout << "Original array: ";
    for (const string& s : arr) {
        cout << s << " ";
    }
    cout << endl;

    radixSortStrings(arr);

    cout << "Sorted array: ";
    for (const string& s : arr) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
