#include "s.h"
/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start
class Solution {
private:
    int dir_x[4] = {0,1,0,-1};
    int dir_y[4] = {1,0,-1,0};
    int m,n;

    void bfs(int sx, int sy, vector<vector<int>>& grid, int test){
        queue<pair<int,int>> q;

        q.push({sx,sy});
        grid[sx][sy]=-1;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nx = x+dir_x[k];
                int ny = y+dir_y[k];

                if(nx>=m || nx<0 || ny<0 || ny>=n || grid[nx][ny]!=test){
                    continue;
                }

                q.push({nx,ny});
                grid[nx][ny]=-1;
            }
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                bfs(i,0, grid, 1);
            }
            if(grid[i][n-1]==1){
                bfs(i,n-1, grid, 1);
            }
            if(grid[i][0]==0){
                bfs(i,0, grid, 0);
            }
            if(grid[i][n-1]==0){
                bfs(i,n-1, grid, 0);
            }
        }

        for(int j=0;j<n;j++){
            if(grid[0][j]==1){
                bfs(0,j, grid,1);
            }
            if(grid[m-1][j]==1){
                bfs(m-1,j, grid,1);
            }
            if(grid[0][j]==0){
                bfs(0,j, grid,0);
            }
            if(grid[m-1][j]==0){
                bfs(m-1,j, grid,0);
            }
        }
        int cnt =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    cnt++;
                    bfs(i,j,grid,0);
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

int main(){

    Solution s;

    vector<vector<int>> grid = {
        {1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}
    };

    vector<vector<int>> grid2={
        {1,1,1,1,1,1,1},
        {1,0,0,0,0,0,1},
        {1,0,1,1,1,0,1},
        {1,0,1,0,1,0,1},
        {1,0,1,1,1,0,1},
        {1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1}
    };

    vector<vector<int>> grid3{
        {0}
    };

    // cout << s.closedIsland(grid);
    // cout << s.closedIsland(grid2);

    cout << s.closedIsland(grid3);

    return 0;
}