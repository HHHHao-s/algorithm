#include "s.h"
/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 */

// @lc code=start
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = m*(1<<(n-1));

        for(int j=1;j<n;j++){
            int ones=0;
            for(int i=0;i<m;i++){
                if(grid[i][0]==1){
                    ones+=grid[i][j];
                }else{
                    ones+=1-grid[i][j];
                }
            }
            ones = max(ones, m-ones);
            ans += ones*(1<<(n-1-j));
        }
        return ans;

        

    }
};
// @lc code=end

