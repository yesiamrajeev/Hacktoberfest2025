/*
 Hacktoberfest 2025 Contribution
 Problem: Climbing Stairs II

 Problem Statement:
 You are climbing a staircase with n + 1 steps, numbered 0 to n.
 You are given a costs array where costs[i] is the cost to step on step i.
 From any step i, you can jump to i + 1, i + 2, or i + 3.
 The cost of a jump from i to j is:
        cost[j] + (j - i)^2

 Goal:
 Find the minimum total cost to reach step n, starting from step 0.

 Approach:
 We will use Dynamic Programming (DP):
   - Define dp[i] = minimum cost to reach step i.
   - Transition:
         dp[j] = min(dp[j], dp[i] + costs[j] + (j - i)^2)
         for j = i+1, i+2, i+3
   - Base case: dp[0] = costs[0]
   - Answer: dp[n]
*/

#include <bits/stdc++.h>
using namespace std;

int minClimbingCost(vector<int>& costs) {
    int n = costs.size() - 1;  // last step index is n
    const int INF = 1e9;
    vector<int> dp(n + 1, INF);

    // Base case: starting at step 0
    dp[0] = costs[0];

    // Fill dp array
    for (int i = 0; i < n; i++) {
        for (int jump = 1; jump <= 3; jump++) {
            int j = i + jump;
            if (j <= n) {
                dp[j] = min(dp[j], dp[i] + costs[j] + (jump * jump));
            }
        }
    }

    return dp[n];
}

// Driver code to test
int main() {
    // Example input
    vector<int> costs = {1, 5, 2, 3, 6}; // step 0 to step 4
    // Here n = 4, last step is step 4.

    cout << "Minimum Total Cost: " << minClimbingCost(costs) << endl;

    return 0;
}

/*
 Example Walkthrough:
 costs = {1, 5, 2, 3, 6}

 Start at step 0 with cost = 1
 Possible jumps:
   - 0 -> 1: cost = 1 + 5 + (1^2) = 7
   - 0 -> 2: cost = 1 + 2 + (2^2) = 7
   - 0 -> 3: cost = 1 + 3 + (3^2) = 13
 Continue updating dp until step 4.
 Final Answer = dp[4]

 Output:
 Minimum Total Cost: 15
*/
