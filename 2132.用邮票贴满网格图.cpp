#include "s.h"
/*
 * @lc app=leetcode.cn id=2132 lang=cpp
 *
 * [2132] 用邮票贴满网格图
 */

// @lc code=start
class Solution {


public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> sum(m+2,vector<int>(n+2)),diff(m+2,vector<int>(n+2));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+grid[i-1][j-1];
            }
        }

        for(int i=1;i+stampHeight-1<=m;i++){
            for(int j=1;j+stampWidth-1<=n;j++){
                int x=i+stampHeight-1;
                int y=j+stampWidth-1;
                if(sum[x][y]-sum[i-1][y]-sum[x][j-1]+sum[i-1][j-1]==0){
                    // no 1
                    diff[i][j]++;
                    diff[i][y+1]--;
                    diff[x+1][j]--;
                    diff[x+1][y+1]++;
                }
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                diff[i][j] += diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
                if(diff[i][j]==0 && grid[i-1][j-1]==0){
                    return false;
                }
            }
        }
        return true;

    }
};
// @lc code=end

int main(){

    Solution s;
    vector<vector<int>>grid ={
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,0,0,0,1},
        {0,0,0,1,1}
    };
    cout << s.possibleToStamp(grid, 2,2);
}