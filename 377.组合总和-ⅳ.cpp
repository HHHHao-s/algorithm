#include "s.h"
/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> dp(target+1);
        dp[0] = 1;
        for(int i=1;i<=target;i++){
            for(int num: nums){
                if(i-num>=0 && dp[i]<INT_MAX -dp[i-num]){
                    dp[i] += dp[i-num];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end

