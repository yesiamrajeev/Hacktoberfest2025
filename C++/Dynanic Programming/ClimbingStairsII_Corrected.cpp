/*
 * Problem: Climbing Stairs II
 * 
 * Problem Statement:
 * You are climbing a staircase with n + 1 steps, numbered 0 to n.
 * You are given a costs array where costs[i] is the cost to step on step i.
 * From any step i, you can jump to i + 1, i + 2, or i + 3.
 * The cost of a jump from i to j is costs[j] + (j - i)^2.
 * Find the minimum total cost to reach step n, starting from step 0.
 * 
 * Approach: Dynamic Programming
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
   
    int minCostClimbingStairs(vector<int>& costs, int n) {
        // dp[i] represents minimum cost to reach step i
        vector<long long> dp(n + 1, LLONG_MAX);
        
        // Base case: starting at step 0 with its cost
        dp[0] = costs[0];
        
        // Fill dp array using bottom-up approach
        for (int i = 0; i < n; i++) {
            // Skip if current step is unreachable
            if (dp[i] == LLONG_MAX) continue;
            
            // Try jumping to i+1, i+2, i+3 (if within bounds)
            for (int jump = 1; jump <= 3 && i + jump <= n; jump++) {
                int nextStep = i + jump;
                // Cost = current cost + step cost + jump penalty (j-i)^2
                long long jumpCost = dp[i] + costs[nextStep] + (long long)(jump * jump);
                dp[nextStep] = min(dp[nextStep], jumpCost);
            }
        }
        
        return (int)dp[n];
    }
    
    int minCostClimbingStairsRecursive(vector<int>& costs, int n) {
        vector<long long> memo(n + 1, -1);
        return (int)solve(costs, 0, n, memo);
    }

private:
    
    long long solve(vector<int>& costs, int current, int target, vector<long long>& memo) {
        // Base case: reached target
        if (current == target) {
            return costs[current];
        }
        
        // Base case: exceeded target
        if (current > target) {
            return LLONG_MAX;
        }
        
        // Return memoized result
        if (memo[current] != -1) {
            return memo[current];
        }
        
        long long minCost = LLONG_MAX;
        
        // Try all possible jumps (1, 2, 3 steps)
        for (int jump = 1; jump <= 3 && current + jump <= target; jump++) {
            int nextStep = current + jump;
            long long cost = solve(costs, nextStep, target, memo);
            
            if (cost != LLONG_MAX) {
                // Add current step cost and jump penalty
                long long totalCost = costs[current] + cost + (long long)(jump * jump);
                minCost = min(minCost, totalCost);
            }
        }
        
        return memo[current] = minCost;
    }
};

void testSolution() {
    Solution solution;
    
    // Test Case 
    vector<int> costs1 = {1, 2, 3, 4, 5};
    int n1 = 4;
    cout << "Test Case 1:" << endl;
    cout << "Costs: [1, 2, 3, 4, 5], Target: " << n1 << endl;
    cout << "Minimum cost (Iterative): " << solution.minCostClimbingStairs(costs1, n1) << endl;
    cout << "Minimum cost (Recursive): " << solution.minCostClimbingStairsRecursive(costs1, n1) << endl;
    cout << endl;
    
}

int main() {
   
    testSolution();
    
    return 0;
}

/*
 * Explanation of the Algorithm:
 * 
 * 1. Dynamic Programming Approach (Bottom-up):
 *    - dp[i] = minimum cost to reach step i
 *    - For each step i, try jumping 1, 2, or 3 steps ahead
 *    - Cost of jump from i to j = dp[i] + costs[j] + (j-i)^2
 *    - Take minimum among all possible jumps
 * 
 * 2. Recursive Approach with Memoization (Top-down):
 *    - solve(current, target) = minimum cost from current to target
 *    - Try all possible jumps and take minimum
 *    - Use memoization to avoid recomputation
 * 
 * 3. Key Points:
 *    - Jump penalty is (j-i)^2 where j-i can be 1, 2, or 3
 *    - So penalties are 1, 4, or 9 respectively
 *    - Must add both step cost and jump penalty
 *    - Handle edge cases and bounds checking
 * 
 * Time Complexity: O(n) - each step processed once with constant jumps
 * Space Complexity: O(n) - for dp array or memoization
 */