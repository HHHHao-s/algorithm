#include "s.h"
/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(const vector<int>& prices, int fee) {
        int n = prices.size();

        // vector<vector<int>> dp(n, vector<int>(2));
        
        // dp[0][0] = -prices[0];
        int ans=0;
        int a=-prices[0],b=0;
        for(int i=1;i<n;i++){
            int price = prices[i];
            a = max({a, b-price});
            b = max(price + a - fee, b);
            ans = max(ans, b);
        }

        return ans;

    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.maxProfit({1,3,7,5,10,3},3);


    return 0;
}