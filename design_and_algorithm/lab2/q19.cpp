#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int pivot) {
    int i = 0;
    for (int j = 0; j < nums.size() - 1; ++j) {
        if (nums[j] >= pivot) {  
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[nums.size() - 1]);
    return i;
}

int kthLargest(vector<int> nums, int k) {
    if (nums.size() < k) {
        return -1;
    }

    int pivot = nums[nums.size() - 1];
    int pivotIndex = partition(nums, pivot);

    if (pivotIndex == k - 1) {
        return nums[pivotIndex];
    } else if (pivotIndex < k - 1) {
        return kthLargest(vector<int>(nums.begin() + pivotIndex + 1, nums.end()), k - pivotIndex - 1);
    } else {
        return kthLargest(vector<int>(nums.begin(), nums.begin() + pivotIndex), k);
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums;
    int k;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << "Enter the value of k:";
    cin >> k;
    int kthLargestElement = kthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << kthLargestElement << endl;
    return 0;
}