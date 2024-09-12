#include "s.h"
/*
 * @lc app=leetcode.cn id=2576 lang=cpp
 *
 * [2576] 求出最多标记下标
 */

// @lc code=start
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = n / 2;
        int res = 0;
        for (int i = 0, j = m; i < m && j < n; i++) {
            while (j < n && 2 * nums[i] > nums[j]) {
                j++;
            }
            if (j < n) {
                res += 2;
                j++;
            }
        }
        return res;
    }
};

// @lc code=end

