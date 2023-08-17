#include "s.h"
/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(const vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>({0,0,0}));
        // int ans = 0;
    
        dp[0][0] = -prices[0];

        for(int i=1;i<n;i++){
            int price = prices[i];

            dp[i][0] = max(dp[i-1][2]-price, dp[i-1][0]); // buy
            dp[i][1] = price + dp[i-1][0]; // sell
            dp[i][2] = max(dp[i-1][1],dp[i-1][2]); // keep
        }


        return max({dp[n-1][1], dp[n-1][2]});
    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.maxProfit({1});

    return 0;
}