#include "s.h"
/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n,{0,0,0,0});

        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;

    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.maxProfit({3,3,5,0,0,3,1,4,0,1,8});

    return 0;
}