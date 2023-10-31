#include "s.h"
/*
 * @lc app=leetcode.cn id=1293 lang=cpp
 *
 * [1293] 网格中的最短路径
 */

// @lc code=start
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int dir_x[4] = {0,1,0,-1};
        int dir_y[4] = {1,0,-1,0};
        struct status
        {
            int x,y,last;
        };
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> vis(m,vector<vector<int>>(n,vector<int>(k+1,0)));
        queue<status> q;      
        q.push({0,0,k});
        vis[0][0][k] = 1;
        int ans=0;

        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto [x,y,last] = q.front();
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nx = x+dir_x[i];
                    int ny = y+dir_y[i];
                    if(nx<m && nx>=0 && ny>=0 && ny<n){
                        if(nx==m && ny==n){
                            return ans;
                        }
                        int nlast = last-grid[nx][ny];
                        if(nlast>=0){
                            if(vis[nx][ny][nlast]==1){
                                continue;
                            }else{
                                vis[nx][ny][nlast]=1;
                                q.push({nx,ny,nlast});
                            }                            
                        }                                      
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
// @lc code=end

