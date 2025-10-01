// Fractional Knapsack Problem

// Given the weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In Fractional Knapsack, we can break items for maximizing the total value of the knapsack

// Note: In the 0-1 Knapsack problem, we are not allowed to break items. We either take the whole item or don’t take it. 

 

// Input: 
// Items as (value, weight) pairs 
// arr[] = {{60, 10}, {100, 20}, {120, 30}} 
// Knapsack Capacity, W = 50

// Output: Maximum possible value = 240 
// Explanation: by taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. 
// Hence total price will be 60+100+(2/3)(120) = 240

 

// Input:  
// Items as (value, weight) pairs 
// arr[] = {{500, 30}}
// Knapsack Capacity, W = 10
// Output: 166.667

// Naive Approach: Try all possible subsets with all different fractions but that will be very inefficient. 

// Greedy approach for fractional knapsack problem:
// An efficient solution is to use the Greedy approach. The basic idea of the greedy approach is to calculate the ratio value/weight for each item and sort the item on the basis of this ratio. Then take the item with the highest ratio and add them until we can’t add the next item as a whole and at the end add the next item as much as we can. Which will always be the optimal solution to this problem.

// Follow the given steps to solve the problem using the above approach:

// Calculate the ratio(value/weight) for each item.
// Sort all the items in decreasing order of the ratio.
// Initialize res =0, curr_cap = given_cap.
// Do the following for every item “i” in the sorted order:
// If the weight of the current item is less than or equal to the remaining capacity then add the value of that item into the result
// else add the current item as much as we can and break out of the loop
// Return res
// Below is the implementation of the above approach:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store value and weight of an item
class Item {
public:
    int value, weight;

    Item(int value, int weight) {
        this->value = value;
        this->weight = weight;
    }
};

// Comparator function to sort items by value/weight ratio in descending order
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Main greedy function to solve the problem
double fractionalKnapsack(int W, vector<Item> &arr) {

    // Sorting items based on value/weight ratio
    sort(arr.begin(), arr.end(), compare);

    double finalValue = 0.0;  // Final result

    // Looping through all items
    for (Item &item : arr) {

        // If adding the whole item won't overflow, add it completely
        if (item.weight <= W) {
            W -= item.weight;
            finalValue += item.value;
        }
        // If we can't add the current item, add the fractional part
        else {
            finalValue += item.value * ((double)W / item.weight);
            break;
        }
    }

    return finalValue;  // Returning the final value
}

int main() {
    int W = 50;  // Weight of knapsack
    vector<Item> arr = { Item(60, 10), Item(100, 20), Item(120, 30) };

    // Function call
    double maxVal = fractionalKnapsack(W, arr);
    cout << "Maximum value we can obtain = " << maxVal << endl;

    return 0;
}