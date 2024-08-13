#include "s.h"
/*
 * @lc app=leetcode.cn id=1866 lang=cpp
 *
 * [1866] 恰有 K 根木棍可以看到的排列数目
 */

// @lc code=start
class Solution {
public:
    int rearrangeSticks(int n, int k) {

        vector<vector<long long>> dp(n+1, vector<long long>(k+1));

        constexpr long long MOD = 1e9+7;

        dp[1][1] = 1;
        for(long long i=2;i<=n;i++){
            for(long long j=1;j<=min((long long)k, i);j++){

                dp[i][j] = (dp[i-1][j-1] + ((i-1)*dp[i-1][j])%MOD)%(MOD);

            }
        }
        if(dp[n][k] <0){
            dp[n][k] += MOD;
        }
        return dp[n][k];

    }
};
// @lc code=end

