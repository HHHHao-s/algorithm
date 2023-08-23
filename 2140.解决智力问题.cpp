#include "s.h"
/*
 * @lc app=leetcode.cn id=2140 lang=cpp
 *
 * [2140] 解决智力问题
 */

// @lc code=start
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long> dp(n+1,0);

        

        for(int i=n;i-->0;){
            long long point = questions[i][0],brainpower = questions[i][1];
            if(i+brainpower+1>=n){
                dp[i]= max(point,dp[i+1]);
            }else{
                dp[i] = max(point+dp[i+brainpower+1], dp[i+1]);
            }

        }
        return dp[0];
    }
};
// @lc code=end

