#include "s.h"
/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        int dir_x[8] = {0,1,0,-1,-1,1,-1,1};
        int dir_y[8] = {1,0,-1,0,-1,1,1,-1};

        queue<pair<int,int>> q;

        vector<vector<int>> vis(n,vector<int>(n));

        q.push({0,0});
        vis[0][0]=1;
        if(grid[0][0]==1){
            return -1;
        }else if(n==1 && grid[0][0]==0){
            return 1;
        }


        int step=1;
        while(!q.empty()){

            int sz = q.size();
            
            for(int i=0;i<sz;i++){

                auto [x,y] = q.front();
                q.pop();

                

                for(int k=0;k<8;k++){
                    int nx = x+dir_x[k];
                    int ny = y+dir_y[k];

                    if(nx<0 || nx>=n || ny<0 || ny>=n || vis[nx][ny]){
                        continue;
                    }

                    if(nx==n-1 && ny ==n-1 && grid[nx][ny]==0){
                        return step+1;
                    }else if( grid[nx][ny]==0){
                        q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }

                }

            }
            step++;
        }

        return -1;


    }
};
// @lc code=end

