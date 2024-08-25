#include "s.h"
/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum= accumulate(nums.begin(), nums.end(),0);
        if(sum % k !=0){
            return false;
        }
        int need = sum / k;
        sort(nums.begin(), nums.end());
        if(nums.back() > need){
            return false;
        }
        int n = nums.size();

        vector<bool> dp(1<<n, true);

        auto dfs = [&](auto && dfs, int s,int p ) ->bool{

            if(s==0){
                return true;
            }
            if(!dp[s]){
                return dp[s];
            }
            dp[s] = false;
            for(int i=0;i<n;i++){
                if(nums[i]+p > need){
                    break;
                }
                if(s & (1<<i)){
                    if(dfs(dfs, (s ^ (1<<i)), (p+nums[i])%need)){
                        return true;
                    }
                }
                
            }
            return false;

        };

        return dfs(dfs, (1<<n)-1, 0);


    }
};
// @lc code=end
