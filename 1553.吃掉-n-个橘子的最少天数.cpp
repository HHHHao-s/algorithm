#include "s.h"
/*
 * @lc app=leetcode.cn id=1553 lang=cpp
 *
 * [1553] 吃掉 N 个橘子的最少天数
 */

// @lc code=start
class Solution {
private:
    unordered_map<int, int> memo;

public:
    int minDays(int n) {
        if (n <= 1) {
            return n;
        }
        if (memo.count(n)) {
            return memo[n];
        }
        return memo[n] = min(n % 2 + 1 + minDays(n / 2), n % 3 + 1 + minDays(n / 3));
    }
};


// @lc code=end

