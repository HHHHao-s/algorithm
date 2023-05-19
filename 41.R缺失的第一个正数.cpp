#include "s.h"
/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 将小于0的改成n+1
        int n = nums.size();
        for (int& num: nums) {
            if (num <= 0) {
                num = n + 1;
            }
        }

        
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            // 返回的结果只有两种可能，要么在[1,N]，要么是N+1，所以大于n的不用看
            if (num <= n) {
                // 将数组下标标记成负数，这样在检查的时候，只用从头开始找第一个不是负数的，说明没有这个数在数组中，这个就是最小的正整数
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
// @lc code=end

