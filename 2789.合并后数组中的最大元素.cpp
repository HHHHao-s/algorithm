#include "s.h"
/*
 * @lc app=leetcode.cn id=2789 lang=cpp
 *
 * [2789] 合并后数组中的最大元素
 */

// @lc code=start
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long ret = 0;
        for(int i=nums.size()-1;i>=0;i--){
            long long tp = nums[i];
            while(i-1>=0 && tp>=nums[i-1]){
                tp += nums[i-1];
                i--;
            }
            ret = max(tp, ret);
        }
        return ret;
    }
};
// @lc code=end

