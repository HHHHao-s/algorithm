#include "s.h"
/*
 * @lc app=leetcode.cn id=2412 lang=cpp
 *
 * [2412] 完成所有交易的初始最少钱数
 */

// @lc code=start
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {

        long long lose_money=0;
        long long mx = 0;
        for(auto &t: transactions){
            long long cost = t[0], cashback=t[1];
            lose_money += max(cost- cashback, 0ll);
            mx = max(mx, min(cost, cashback));
        }
        return lose_money+mx;

    }
};
// @lc code=end

