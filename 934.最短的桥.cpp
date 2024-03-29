#include "s.h"
/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution {
public:
    queue<tuple<int, int, int>> q2;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int n;

    int bfs2(vector<vector<int>>& grid){

        while (!q2.empty())
        {
            auto [x,y,len] = q2.front();
            q2.pop();
            

            for (int k = 0; k < 4; ++k){
                int nx = x + dx[k];
                int ny = y + dy[k];
            
                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    if(grid[nx][ny]==0){
                        q2.push({nx,ny,len+1});
                        grid[nx][ny] = 2;
                    }else if(grid[nx][ny]==1){
                        return len;
                    }
                    
                }
            }
        }

        return 0;

    }

    void bfs1(int _x, int _y,vector<vector<int>>& grid){ // 找到整个岛

        queue<pair<int, int>> q;

        q.push({_x,_y});
        grid[_x][_y] = 2;
        while (!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();
            
            
            int sum=0;
            for (int k = 0; k < 4; ++k){
                int nx = x + dx[k];
                int ny = y + dy[k];
            
                if(nx>=0 && nx<n && ny>=0 && ny<n ){
                    if(grid[nx][ny]==1){
                        q.push({nx,ny});
                        grid[nx][ny] = 2;
                    }
                    if(grid[nx][ny]==0){
                        sum++; //统计相邻的水个数
                    }
                     
                }

            }
            if(sum!=0){
                q2.push({x,y,0});
            }
        }

    }


    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();

        queue<tuple<int, int, int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    bfs1(i,j,grid);
                    return bfs2(grid);
                    
                }
            }      
        }

        return -1;

    }
};
// class Solution {
// public:
//     int shortestBridge(vector<vector<int>>& grid) {
//         int n = grid.size();
//         vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
//         vector<pair<int, int>> island;
//         queue<pair<int, int>> qu;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 1) {
//                     qu.emplace(i, j);
//                     grid[i][j] = -1;
//                     while (!qu.empty()) {
//                         auto [x, y] = qu.front();
//                         qu.pop();
//                         island.emplace_back(x, y);
//                         for (int k = 0; k < 4; k++) {
//                             int nx = x + dirs[k][0];
//                             int ny = y + dirs[k][1];
//                             if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1) {
//                                 qu.emplace(nx, ny);
//                                 grid[nx][ny] = -1;
//                             }
//                         }
//                     }
//                     for (auto &&[x, y] : island) {
//                         qu.emplace(x, y);
//                     }
//                     int step = 0;
//                     while (!qu.empty()) {
//                         int sz = qu.size();
//                         for (int i = 0; i < sz; i++) {
//                             auto [x, y] = qu.front();
//                             qu.pop();
//                             for (int k = 0; k < 4; k++) {
//                                 int nx = x + dirs[k][0];
//                                 int ny = y + dirs[k][1];
//                                 if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
//                                     if (grid[nx][ny] == 0) {
//                                         qu.emplace(nx, ny);
//                                         grid[nx][ny] = -1;
//                                     } else if (grid[nx][ny] == 1) {
//                                         return step;
//                                     }
//                                 }
//                             }
//                         }
//                         step++;
//                     }
//                 }
//             }
//         }
//         return 0;
//     }
// };

// @lc code=end

int main(){

    Solution s;

    vector<vector<int>> grid={
        {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}
    };

    cout << s.shortestBridge(grid);


    return 0;
}