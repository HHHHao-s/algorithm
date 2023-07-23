#include "s.h"
/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {

        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1));


        for(int i=0;i<=m;i++){
            dp[i][0] = i;
        }
        for(int i=0;i<=n;i++){
            dp[0][i] = i;
        }

        for(int i=1;i<=m;i++){
            char c1 = word1[i-1];
            for(int j=1;j<=n;j++){
                char c2 = word2[j-1];
                if(c1==c2){
                    dp[i][j] = 1+ min(dp[i-1][j],min(dp[i][j-1], dp[i-1][j-1]-1));
                }else{
                    dp[i][j] = 1+ min(dp[i-1][j],min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }

        return dp[m][n];

    }
};
// @lc code=end

