#include "s.h"
/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
private:
    int dir_x[4] = {0,1,0,-1};
    int dir_y[4] = {1,0,-1,0};
    int n,m;

    vector<vector<int>> vis;
    


    void bfs(int sx,int sy, vector<vector<int>>& heights, vector<vector<int>>& ocean){

        queue<pair<int,int>> q;

        q.push({sx,sy});
        vis[sx][sy] = 1;
        ocean[sx][sy] = 1;

        while(!q.empty()){
            
            auto [x,y] = q.front();
            q.pop();
            int height = heights[x][y];

            for(int k=0;k<4;k++){
                int nx = x+dir_x[k];
                int ny = y+dir_y[k];

                if(nx<0||nx>=m||ny<0||ny>=n||vis[nx][ny]||heights[nx][ny]<heights[x][y]){
                    continue;
                }

                q.push({nx,ny});
                vis[nx][ny]=1;
                ocean[nx][ny]=1;
            }


        }
        

    } 

public:
    
      

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vis = vector<vector<int>>(m,vector<int>(n));
        
        vector<vector<int>> pacific(m,vector<int>(n));
        vector<vector<int>> atlantic(m,vector<int>(n));

        for(int i=0;i<m;i++){           
            if(!vis[i][0]){
                bfs(i,0,heights,pacific);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[0][i]){
                bfs(0,i,heights,pacific);
            }
        }

        vis = vector<vector<int>>(m,vector<int>(n)); 

        for(int i=0;i<m;i++){
            if(!vis[i][n-1]){
                bfs(i,n-1,heights, atlantic);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[m-1][i]){
                bfs(m-1,i,heights,atlantic);
            }
        }

        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atlantic[i][j]&&pacific[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;

    }
};

// @lc code=end

int main(){

    Solution s;

    vector<vector<int>> heights={
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };

    vector<vector<int>> heights2={
        {1,1},
        {1,1},
        {1,1}
    };



    print2d(s.pacificAtlantic(heights));


    return 0;
}