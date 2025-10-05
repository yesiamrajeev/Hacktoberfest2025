#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0/1 Knapsack problem
int knapsack(int W, vector<int> &weights, vector<int> &values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter maximum weight capacity of the knapsack: ";
    cin >> W;

    vector<int> values(n), weights(n);
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> values[i];

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> weights[i];

    int maxProfit = knapsack(W, weights, values, n);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
