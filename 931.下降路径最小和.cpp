#include "s.h"
/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n);
        vector<int> sb(n);
        for(int i=0;i<n;i++){
            dp[i] = matrix[0][i];
        }

        for(int i=1;i<n;i++){
            
            sb[0] = min(dp[0], dp[1]) + matrix[i][0];
            for(int j=1;j<n-1;j++){
                sb[j] = min(min(dp[j-1], dp[j]), dp[j+1]) + matrix[i][j];
            }
            sb[n-1] = min(dp[n-2], dp[n-1]) + matrix[i][n-1];
            dp = sb;
        }


        int ans = 1000000000;
        for(int i=0;i<n;i++){
            ans = min(ans, dp[i]);
        }

        return ans;


    }
};
// @lc code=end

