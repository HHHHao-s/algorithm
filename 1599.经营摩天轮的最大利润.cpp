#include "s.h"
/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 *
 * [1599] 经营摩天轮的最大利润
 */

// @lc code=start
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& nums, int gain, int cost) {
        int n = nums.size();
        int board = 0, x = 0, mx = 0, i = 0, ans = -1;
        while (true) {
            if (i < n) board += nums[i];
            int player = min(board, 4);
            board -= player;
            x += player * gain - cost;
            if (x > mx) mx = x, ans = i + 1;
            if (i++ >= n && !board) break;
        }
        return ans;
    }
};
// @lc code=end

