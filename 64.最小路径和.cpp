#include "s.h"
/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,100000000));
        dp[0][0] = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int tmp = dp[i][j];
                if(j>0){
                    tmp = min(tmp, dp[i][j-1]);
                }
                if(i>0){
                    tmp = min(tmp, dp[i-1][j]);
                }
                dp[i][j] = tmp + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};
// @lc code=end

int main(){

    Solution s;

    vector<vector<int>> grid = {
        {1,2,3},
        {4,5,6},

    };

    cout << s.minPathSum(grid);


    return 0;
}