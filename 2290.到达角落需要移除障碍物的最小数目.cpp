#include "s.h"
/*
 * @lc app=leetcode.cn id=2290 lang=cpp
 *
 * [2290] 到达角落需要移除障碍物的最小数目
 */

// @lc code=start
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m ,vector<int>(n, INT_MAX));
        deque<tuple<int,int,int>> q;
        q.push_back({0,0,0}); // x,y,removed
        vis[0][0] = 0;
        int cur_ans=INT_MAX;
        int dir_x[4] = {0,1,0,-1};
        int dir_y[4] = {1,0,-1,0};
        while(!q.empty()){
            auto [x,y,removed] = q.front();
            q.pop_front();

            
            for(int i=0;i<4;i++){
                int nx = x+dir_x[i];
                int ny = y+dir_y[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    int r = removed+grid[nx][ny];
                    
                    if(vis[nx][ny]> r){
                        vis[nx][ny] = r;
                        if(grid[nx][ny]==0){
                            // 优先走0
                            q.push_front({nx, ny,r});

                        }else{
                            q.push_back({nx,ny,r});
                        }
                    }
                }
            }

        }
        return vis[m-1][n-1];
    }
};
// @lc code=end

