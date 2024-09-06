#include "s.h"
/*
 * @lc app=leetcode.cn id=3176 lang=cpp
 *
 * [3176] 求出最长好子序列 I
 */

// @lc code=start
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(nums.size(), vector<int>(k+1, 0));
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        int ret= 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]!=nums[j]){
                    for(int l=0;l<=k-1;l++){
                        dp[i][l+1] = max( dp[j][l] + 1, dp[i][l+1]);
                        ret = max(ret, dp[i][l+1]);
                    }
                }else{
                    for(int l=0;l<=k;l++){
                        dp[i][l] = max( dp[i][l],dp[j][l] + 1);
                        ret = max(ret, dp[i][l]);
                    }
                }
            }
        }

        return ret;

    }
};
// @lc code=end

