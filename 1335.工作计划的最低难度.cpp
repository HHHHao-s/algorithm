#include "s.h"
/*
 * @lc app=leetcode.cn id=1335 lang=cpp
 *
 * [1335] 工作计划的最低难度
 */

// @lc code=start
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {


        int n = jobDifficulty.size();
        if(n<d){
            return -1;
        }


        vector<vector<int>> dp(n ,vector<int>(d+1, 100000000));
        int ma= 0;
        for(int i=0;i<n;i++){
            ma = max(ma, jobDifficulty[i]);
            dp[i][0] = ma;
        }

        for(int i=1;i<d;i++){
            for(int j=i;j<n;j++){
                ma = 0;
                for(int k=j;k>=i;k--){
                    ma = max(ma, jobDifficulty[k]);
                    dp[j][i] = min(dp[j][i], ma+dp[k-1][i-1]);
                }

            }

        }

        return dp[n-1][d-1];


    }
};
// @lc code=end

