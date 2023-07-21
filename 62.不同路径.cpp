#include "s.h"
/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j>0){
                    dp[i][j] += dp[i][j-1];
                }
                if(i>0){
                    dp[i][j] += dp[i-1][j];
                }
            }
        }

        return dp[m-1][n-1];

    }
};
// @lc code=end

int main(){

    Solution s;
    cout << s.uniquePaths(7,3);


    return 0;
}