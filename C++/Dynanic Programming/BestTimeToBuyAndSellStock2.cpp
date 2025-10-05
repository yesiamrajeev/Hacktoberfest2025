// Problem Link:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                dp[i][0] = 0;
                dp[i][1] = prices[i];
                continue;
            }
            dp[i][0] = max(dp[i+1][1] - prices[i],dp[i+1][0]);
            dp[i][1] = max(dp[i+1][1] , dp[i+1][0] + prices[i]);
        }
        return dp[0][0];
    }
};
