#include "s.h"
/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution {
private:
    int dir_x[4] = {0,1,0,-1};
    int dir_y[4] = {1,0,-1,0};
    int m,n;

    void bfs(int sx, int sy, vector<vector<int>>& grid){
        queue<pair<int,int>> q;

        q.push({sx,sy});
        grid[sx][sy]=0;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nx = x+dir_x[k];
                int ny = y+dir_y[k];

                if(nx>=m || nx<0 || ny<0 || ny>=n || grid[nx][ny]==0){
                    continue;
                }

                q.push({nx,ny});
                grid[nx][ny]=0;
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                bfs(i,0, grid);
            }
            if(grid[i][n-1]==1){
                bfs(i,n-1, grid);
            }
        }

        for(int j=0;j<n;j++){
            if(grid[0][j]==1){
                bfs(0,j, grid);
            }
            if(grid[m-1][j]==1){
                bfs(m-1,j, grid);
            }
        }
        int cnt =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

int main(){


    Solution sl;
    vector<vector<int>> grid ( {
        {0,1,1,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,0,0}
    });
    
    cout << sl.numEnclaves(grid) << endl;
    


    return 0;
}