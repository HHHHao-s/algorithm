#include "s.h"
/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return;
        }
        int last = -1;

        for(int i=n-1;i-->0;){
            if(nums[i+1]>nums[i]){
                last = i;
                break;
            }
        }
        if(last == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i=n;i-->0;){
            if(nums[i]>nums[last]){
                swap(nums[i], nums[last]);
                reverse(nums.begin()+last+1, nums.end());
                break;
            }
        }
    }
};
// @lc code=end

