#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Item structure to store weight, value and value-to-weight ratio
struct Item {
int weight;
int value;
// Constructor
Item(int w, int v) : weight(w), value(v) {}
// Function to calculate the value-to-weight ratio
double valuePerWeight() const {
return (double)value / (double)weight;
}
};
// Comparator function to sort items by their value-to-weight ratio in descending
//order
bool compare(const Item &a, const Item &b) {
return a.valuePerWeight() > b.valuePerWeight();
}
// Function to solve the Fractional Knapsack Problem
double fractionalKnapsack(int knapsackCapacity, vector<Item> &items) {
// Step 1: Sort items by value-to-weight ratio in descending order
sort(items.begin(), items.end(), compare);
double totalValue = 0.0; // Maximum total value that can be obtained
int currentWeight = 0; // Current weight of the knapsack
// Step 2: Iterate through all items and add them to the knapsack
for (const Item &item : items) {
// If adding the entire item does not exceed capacity
if (currentWeight + item.weight <= knapsackCapacity) {
currentWeight += item.weight;
totalValue += item.value;
}
// If adding the entire item exceeds capacity, take a fraction of it
else {
int remainingCapacity = knapsackCapacity - currentWeight;
totalValue += item.valuePerWeight() * remainingCapacity;
break; // Once a fraction of an item is added, the knapsack is full
}
}
return totalValue;
}
int main() {
int n; // Number of items
int knapsackCapacity; // Capacity of the knapsack
cout << "Enter the number of items: ";
cin >> n;
cout << "Enter the knapsack capacity: ";
cin >> knapsackCapacity;
vector<Item> items;
// Input items (weight and value)
for (int i = 0; i < n; i++) {
int weight, value;
cout << "Enter weight and value for item " << i + 1 << ": ";
cin >> weight >> value;
items.push_back(Item(weight, value));
}
// Calculate the maximum value
double maxValue = fractionalKnapsack(knapsackCapacity, items);
// Output the result
cout << "Maximum total value in the knapsack: " << maxValue << endl;
return 0;
}
