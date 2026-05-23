#include <iostream>
#include <vector>
#include <algorithm>

int max_subset_difference(std::vector<int>& arr, int k) {
    std::sort(arr.begin(), arr.end());
    int sum_first_k = 0;
    for (int i = 0; i < k; ++i) {
        sum_first_k += arr[i];
    }
    int sum_remaining = 0;
    for (int i = k; i < arr.size(); ++i) {
        sum_remaining += arr[i];
    }
    int max_difference = sum_remaining - sum_first_k;
    return max_difference;
}

int main() {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    int k = 3;
    int result = max_subset_difference(arr, k);
    std::cout << "Maximum difference between the sum of subsets: " << result << std::endl;
    return 0;
}
