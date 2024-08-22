#include "s.h"
/*
 * @lc app=leetcode.cn id=2444 lang=cpp
 *
 * [2444] 统计定界子数组的数目
 */

// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int> &nums, int min_k, int max_k) {
        long long ans = 0;
        int n = nums.size(), min_i = -1, max_i = -1, i0 = -1;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (x == min_k) min_i = i;
            if (x == max_k) max_i = i;
            if (x < min_k || x > max_k) i0 = i; // 子数组不能包含 nums[i0]
            ans += max(min(min_i, max_i) - i0, 0);
        }
        return ans;
    }
};

// @lc code=end

