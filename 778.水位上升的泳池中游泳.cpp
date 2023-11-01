#include "s.h"
/*
 * @lc app=leetcode.cn id=778 lang=cpp
 *
 * [778] 水位上升的泳池中游泳
 */

// @lc code=start
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        struct status{
            int x, y;
        };
        map<int ,queue<status>> need;
        int dir_x[4]={0,1,0,-1};
        int dir_y[4]={1,0,-1,0};
        need[grid[0][0]].push({0,0});
        int m = grid.size();
        int n = grid[0].size();
        if(n==1){
            return grid[0][0];
        }
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        while(1){
            auto it = need.begin();
            
            int k = it->first;
            queue<status> nodes = std::move(it->second);
            need.erase(k);
            while(!nodes.empty()){
                auto [x,y] = nodes.front();
                nodes.pop();
                vis[x][y] = 1;
                
                for(int i=0;i<4;i++){
                    int nx = x+dir_x[i];
                    int ny = y+dir_y[i];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                        

                        if(grid[nx][ny]<=k){
                            if(nx==m-1 && ny==n-1){
                                return k;
                            }
                            vis[nx][ny] = 1;
                            nodes.push({nx,ny});
                        }else{
                            if(nx==m-1 && ny==n-1){
                                return grid[nx][ny];
                            }
                            need[grid[nx][ny]].push({nx,ny});
                        }
                    }
                }
            }

        } 
        return 0;

    }
};
// @lc code=end

int main(){
    Solution s;

    vector<vector<int>> grid={{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    cout << s.swimInWater(grid);

}