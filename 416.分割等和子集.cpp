#include "s.h"
/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = 0, maxNum = 0;
        for (auto& num : nums) {
            sum += num;
            maxNum = max(maxNum, num);
        }
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }

        vector<vector<bool>> dp(n,vector<bool>(target+1, false));
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        for(int i=1;i<n;i++){
            int num = nums[i];
            for(int j=1;j<=target;j++){
                if(j>=num){
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-num];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n-1][target];
    }
};
// @lc code=end

