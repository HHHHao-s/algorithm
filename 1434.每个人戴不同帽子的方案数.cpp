#include "s.h"
/*
 * @lc app=leetcode.cn id=1434 lang=cpp
 *
 * [1434] 每个人戴不同帽子的方案数
 */

// @lc code=start
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<vector<int>> dp(41, vector<int>(1<<n));

        vector<vector<int>> hatToPerson(41);

        for(int i=0;i<n;i++){
            for(auto h: hats[i]){
                hatToPerson[h].push_back(i);
            }
        }
        dp[0][0] = 1;
        const int MOD = 1e9+7;
        for(int i=1;i<=40;i++){
            for(int j=0;j<(1<<n);j++){
                dp[i][j] = dp[i-1][j];
                for(int k: hatToPerson[i]){
                    if(j&(1<<k)){
                        dp[i][j] += dp[i-1][j^(1<<k)];
                        dp[i][j] %= MOD;
                    }
                    
                }
            }
        }

        return dp[40][(1<<n)-1];


    }
};
// @lc code=end

