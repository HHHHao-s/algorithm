#include "s.h"
/*
 * @lc app=leetcode.cn id=910 lang=cpp
 *
 * [910] 最小差值 II
 */

// @lc code=start

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = nums.back() - nums[0];
        int n = nums.size();
        for (int i = 0; i < n-1; ++i)
        {
            int l = min(nums[0]+k, nums[i+1]-k);
            int h = max(nums[n-1]-k, nums[i]+k);
            res = min(res, h-l);
        }

        return res;
    }
};

// @lc code=end

