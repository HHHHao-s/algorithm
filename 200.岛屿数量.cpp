#include "s.h"

/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
// class Solution {
// public:

//     // vector<vector<bool>> visited;

//     int visits=0;
//     int grids=0;

//     int n,m;

//     int dfs(vector<vector<char>>& grid, int x,int y){
//         if(x<0 || x>=n || y<0 || y>=m || grid[y][x]=='0') return 0;
//         else{
//             grid[y][x] = '0';

//             dfs(grid,x+1,y);
//             dfs(grid,x,y+1);
//             dfs(grid,x-1,y);
//             dfs(grid,x,y-1);


//             return 1;
//         }
//     }



//     int numIslands(vector<vector<char>>& grid) {
//         n = grid[0].size();
//         m = grid.size();
//         visits=0;
//         grids = 0;
        
        
        

//         for(int y=0;y<m;y++){
//             for(int x=0;x<n;x++){
//                 if(grid[y][x]=='1'){
//                     dfs(grid, x,y);
//                     grids++;
//                 }

//             }
//         }
//         return grids;
//     }
// };
// @lc code=start
class Solution
{
private:
    /* data */
    int dir_x[4] = {0,1,0,-1};
    int dir_y[4] = {1,0,-1,0};
public:
    int numIslands(vector<vector<char>>&grid){
        int n = grid[0].size();
        int m = grid.size();
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    
                    queue<pair<int,int>> q;

                    q.push({i,j});
                    grid[i][j]=0;
                    while(!q.empty()){
                        auto [x,y] = q.front();
                        q.pop();

                        for(int k=0;k<4;k++){
                            int nx = x+dir_x[k];
                            int ny = y+dir_y[k];

                            if(nx>=m || nx<0 || ny<0 || ny>=n || grid[nx][ny]=='0'){
                                continue;
                            }

                            q.push({nx,ny});
                            grid[nx][ny]='0';
                        }
                    }

                }
            }
        }
        return cnt;

    }
};


// @lc code=end

int main(){


    Solution sl;
    vector<vector<char>> grid ( {
        {'1','1','1','1','0'},
        {'1','1','0','0','0'},
        {'1','1','0','1','0'},
        {'0','0','1','0','1'}
    });
    vector<vector<char>> grid2 (
        {
            {'1'}
        }
    );
    cout << sl.numIslands(grid) << endl;
    cout << sl.numIslands(grid2) << endl;


    return 0;
}