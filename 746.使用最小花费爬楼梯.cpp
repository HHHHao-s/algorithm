#include "s.h"
/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int a=cost[0], b=cost[1];

        for(int i=2;i<n;i++){
            int x = cost[i];
            int next = min(a+x, b+x);
            a = b;
            b = next;

        }

        return min(a,b);
        
    }
};
// @lc code=end

