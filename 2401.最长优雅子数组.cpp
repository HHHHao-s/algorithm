#include "s.h"
/*
 * @lc app=leetcode.cn id=2401 lang=cpp
 *
 * [2401] 最长优雅子数组
 */

// @lc code=start
class Solution {

public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;
        for(int l=0,r=0,cur=0;r<nums.size();r++){
            while(cur & nums[r]){
                cur ^= nums[l++];
            }
            cur |= nums[r];
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
// @lc code=end

