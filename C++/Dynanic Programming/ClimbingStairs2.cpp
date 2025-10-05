//Problem Link https://leetcode.com/problems/climbing-stairs-ii/

#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
class Solution {
public:

    //recursive + memoization
    ll func(const vector<int>& costs, const int& n, int i, vector<ll>& dp){
        if(i > n){
            return 1e10;
        }
        
        if(i == n){
            return 0;
        }
        

        if(dp[i] != -1){
            return dp[i];
        }
        
        ll a, b, c;
        a = b = c = 1e10;
        
        if(i >= 0 && i < n){
            a = func(costs, n, i + 1, dp) + (ll)costs[i] + 1;
        }

        if(i + 1 < n){
            b = func(costs, n, i + 2, dp) + (ll)costs[i + 1] + 4;
        }

        if(i + 2 < n){
            c = func(costs, n, i + 3, dp) + (ll)costs[i + 2] + 9;
        }

        return dp[i] = min({a, b, c});
    }

    int climbStairs(int n, vector<int>& costs) {
        //to use recursive + memoization
        // vector<ll> dp(n + 1, -1);
        // return func(costs, n, 0, dp);
        
        //tabulation
        vector<ll> dp(n + 1, 1e10);
        dp[0] = 0;
        
        for(int i = 0; i < n; i++){
            if(dp[i] == 1e18)
                continue;
            
            if(i + 1 <= n){
                dp[i + 1] = min(dp[i + 1], dp[i] + costs[i] + 1);
            }

            if(i + 2 <= n){
                 dp[i + 2] = min(dp[i + 2], dp[i] + costs[i + 1] + 4);   
            }

            if(i + 3 <= n){
                dp[i + 3] = min(dp[i + 3], dp[i] + costs[i + 2] + 9);
            }
        }

        return dp[n];
    }
};