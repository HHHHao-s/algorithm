#include "s.h"
/*
 * @lc app=leetcode.cn id=1568 lang=cpp
 *
 * [1568] 使陆地分离的最少天数
 */

// @lc code=start
class Solution {
private:


    vector<vector<pair<int,int>>> four_neighbour{5};
    int dir_x[4] = {0,1,0,-1};
    int dir_y[4] = {1,0,-1,0};
    int m,n;
    void bfs(vector<vector<int>>& grid, int x, int y){
        queue<pair<int,int>> q;
        // vector<vector<int>> vis = grid;
        q.push({x,y});
        grid[x][y]=-1;
        while(!q.empty()){
            auto [tx, ty] = q.front();
            q.pop();
            int nb=0;
            for(int i=0;i<4;i++){
                int nx = tx+dir_x[i];
                int ny = ty+dir_y[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(grid[nx][ny]==-1){
                        continue;
                    }else if(grid[nx][ny]==0){
                        nb++;
                    }else{
                        q.push({nx,ny});
                        grid[nx][ny]=-1;
                    }
                }else{
                    nb++;
                }
            }
            four_neighbour[nb].push_back({tx,ty});
        }

    }

    int findIsland(vector<vector<int>>& grid){
        int island = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    island++;
                    if(island==2){
                        return island;
                    }
                    bfs(grid, i,j);
                }
                
            }
        }
        return island;
    }

public:
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        auto cp = grid;
        int island = findIsland(grid);
        if(island==2 || island == 0){
            return 0;
        }
        int ans = 0;
        if(four_neighbour[4].size()>0){
            return 1;
        }

        if(four_neighbour[3].size()>0){

            grid = cp;
            auto [tx,ty] = four_neighbour[3][0];
            for(int i=0;i<4;i++){
                int nx = tx+dir_x[i];
                int ny = ty+dir_y[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(grid[nx][ny]==1){
                        grid[nx][ny]=0;
                        break;
                    }
                }
            }
            four_neighbour = vector<vector<pair<int,int>>>(5);
            int island = findIsland(grid);
            if(island==2 || island == 0){
                return 1;
            }else{
                return 2;
            }
            

        }else{
            auto cur_nei = four_neighbour[2];
            for(auto [tx,ty]: cur_nei){
                grid = cp;
                for(int i=0;i<4;i++){
                int nx = tx+dir_x[i];
                int ny = ty+dir_y[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(grid[nx][ny]==1){
                            grid[nx][ny]=0;
                            break;
                        }
                    }
                }
                int island = findIsland(grid);
                if(island==2 || island == 0){
                    return 1;
                }
               
            }
            
            return 2;

        }
        return 0;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> grid = {
        {1,1,0,1,1},
        {1,1,1,1,1},
        {1,1,0,1,1},
        {1,1,0,1,1}
    };
    cout << s.minDays(grid);
}