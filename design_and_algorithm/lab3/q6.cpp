#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int value;
    int weight;
    double valuePerWeight; // Value-to-weight ratio
};

// Comparison function to sort items based on value-to-weight ratio in descending order
bool compareItems(const Item& a, const Item& b) {
    return a.valuePerWeight > b.valuePerWeight;
}

// Function to solve the Fractional Knapsack Problem using a greedy approach
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sort items based on value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;

    // Fill the knapsack greedily
    for (const Item& item : items) {
        if (capacity >= item.weight) {
            // Take the entire item if it fits in the knapsack
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            // Take a fraction of the item if it doesn't fit entirely
            totalValue += (static_cast<double>(capacity) / item.weight) * item.value;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    // Example usage
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 30;

    double result = fractionalKnapsack(capacity, items);

    cout << "Maximum value in the knapsack: " << result << endl;

    return 0;
}