#include "s.h"
/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
private:
    int dir_x[4] = {0,1,0,-1};
    int dir_y[4] = {1,0,-1,0};

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){

                    queue<pair<int,int>> q; 
                    int cnt=0;
                    q.push({i,j});
                    grid[i][j]=0;

                    while(!q.empty()){

                        cnt++;
                        auto [x,y] = q.front();
                        q.pop();

                        for(int k=0;k<4;k++){
                            int nx = x+dir_x[k];
                            int ny = y+dir_y[k];

                            if(nx>=m || nx<0 || ny<0 || ny>=n || grid[nx][ny]==0){
                                continue;
                            }

                            q.push({nx,ny});
                            grid[nx][ny] = 0;
                        }

                        

                    }

                    ans = max(ans,cnt);

                }
            }
        }

        return ans;

    }
};
// @lc code=end

