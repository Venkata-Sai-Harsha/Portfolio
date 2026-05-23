#include <iostream>
#include <vector>

int largest_sum_contiguous_array(const std::vector<int>& arr, int k) {
    // Calculate the sum of the given array
    int array_sum = 0;
    for (int num : arr) {
        array_sum += num;
    }

    // If the sum is negative, return 0
    if (array_sum < 0) {
        return 0;
    }

    // Calculate the maximum sum in the modified array
    int max_sum = array_sum + (k - 2) * array_sum;

    return max_sum;
}

int main() {
    // Example usage:
    std::vector<int> arr = {1, 2, 3};
    int k = 4;

    int result = largest_sum_contiguous_array(arr, k);
    std::cout << "The largest sum of contiguous array in the modified array is: " << result << std::endl;

    return 0;
}
