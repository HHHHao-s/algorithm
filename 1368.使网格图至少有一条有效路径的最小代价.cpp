#include "s.h"
/*
 * @lc app=leetcode.cn id=1368 lang=cpp
 *
 * [1368] 使网格图至少有一条有效路径的最小代价
 */

// @lc code=start
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int dirx[5] = {0,0,0,1,-1};
        int diry[5] = {0,1,-1,0,0};

        int m = grid.size();
        int n = grid[0].size();


        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        deque<pair<int,int>> dq;

        dq.push_back({0,0});
        dp[0][0] = 0;

        while(!dq.empty()){

            auto [x,y] = dq.front();
            dq.pop_front();
            if(x==m-1 && y==n-1){
                continue;
            }

            for(int i=1;i<=4;i++){

                int nx=x+dirx[i];
                int ny = y+diry[i];
                if(nx<0 || ny <0 || nx>=m || ny>=n){
                    continue;
                }
                if(grid[x][y] == i ){
                    if( dp[nx][ny]>dp[x][y]){
                        dp[nx][ny] = dp[x][y];
                        dq.push_back({nx,ny});
                    }
                    
                }else {
                    if(dp[nx][ny]>dp[x][y]+1){
                        dp[nx][ny] = dp[x][y]+1;
                        dq.push_back({nx,ny});
                    }
                }


            }

        }

        return dp[m-1][n-1];


    }
};
// @lc code=end

