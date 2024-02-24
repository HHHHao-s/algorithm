#include "s.h"
/*
 * @lc app=leetcode.cn id=1970 lang=cpp
 *
 * [1970] 你能穿过矩阵的最后一天
 */

// @lc code=start
class Solution {
private:
    int dirx[4]={0,1,-1,0};
    int diry[4]={1,0,0,-1};

public:
    int latestDayToCross(int m, int n, vector<vector<int>>& cells) {
        
        auto check = [&](int day){

            vector<vector<int>> grid(m, vector<int>(n));
            for(int i=0;i<day;i++){
                grid[cells[i][0]-1][cells[i][1]-1] = 1;
            }
            queue<pair<int,int>> q;
            for(int i=0;i<n;i++){
                if(grid[0][i]!=1){
                    q.push({0, i});
                    grid[0][i] = 2;
                }
            }
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x+dirx[i];
                    int ny = y+diry[i];
                    if(nx<0 || nx>=m || ny<0 || ny>=n || grid[nx][ny]!=0){
                        continue;
                    }
                    if(nx==m-1){
                        return 1;
                    }
                    q.push({nx, ny});
                    grid[nx][ny] = 2;
                    
                }
            }

            return 0;
        };

        int l = 0;
        int r = m*n;

        while(l<=r){
            int mid = (l+r)/2;
            if(check(mid)){
                l= mid+1;
            }else{
                r=mid-1;
            }
        }
        return l-1;

    }
};
// @lc code=end

