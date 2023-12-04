#include "s.h"
/*
 * @lc app=leetcode.cn id=1210 lang=cpp
 *
 * [1210] 穿过迷宫的最少移动次数
 */

// @lc code=start
class Solution {
private:
    struct Status{
            int x1,y1;
            int x2,y2;
            int dir;
    };
    int calc(int x1,int y1, int x2, int y2, int dir){
        
        int ret= (dir==0?1:114514)+(x1*117+y1);
        cout << ret << endl;
        return ret;
    }

public:
    int minimumMoves(vector<vector<int>>& grid) {

        
        int m = grid.size();
        int n = grid[0].size();

        queue<Status> q;
        q.push({0,0,0,1, 0});
        unordered_set<int> vis;
        vis.insert(calc(0,0,0,1, 0));

        

        int step=0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz; i++){
                auto [x1, y1, x2,y2, dir] = q.front();
                q.pop();
                
                if(dir==0){
                    if(y2+1<n && grid[x2][y2+1]!=1 && !vis.count(calc(x1, y1+1, x2, y2+1, 0))){
                        
                        q.push({x1, y1+1, x2, y2+1, 0});
                        vis.insert(calc(x1, y1+1, x2, y2+1, 0));
                    }
                    if(x1+1<m && x2+1<m && grid[x1+1][y1]!=1 && grid[x2+1][y2]!=1){
                        if(!vis.count(calc(x1+1, y1, x2+1, y2, 0))){
                            q.push({x1+1, y1, x2+1, y2, 0});
                            vis.insert(calc(x1+1, y1, x2+1, y2, 0));
                        }
                            
                        if(!vis.count(calc(x1, y1, x2+1, y1, 1))){
                            q.push({x1, y1, x2+1, y1, 1});
                            vis.insert(calc(x1, y1, x2+1, y1, 1));

                        }
                    }
                    if(x1+1==m && x2+1==m && y1==n-2 && y2==n-1){
                        return step;
                    }
                    
                }else{
                    if(x2+1<m && grid[x2+1][y2]!=1 && !vis.count(calc(x1+1, y1, x2+1, y2, 1))){
                        q.push({x1+1, y1, x2+1, y2, 1});
                        vis.insert(calc(x1+1, y1, x2+1, y2, 1));
                    }
                    if(y1+1<n && y2+1<n && grid[x1][y1+1]!=1 && grid[x2][y2+1]!=1){
                        if(!vis.count(calc(x1, y1+1, x2, y2+1, 1))){
                            q.push({x1, y1+1, x2, y2+1, 1});
                            vis.insert(calc(x1, y1+1, x2, y2+1, 1));
                        }
                            
                        if(!vis.count(calc(x1, y1, x1, y1+1, 0))){
                            q.push({x1, y1, x1, y1+1, 0});
                            vis.insert(calc(x1, y1+1, x2, y2+1, 1));
                        }
                            
                    }
                }
                
            }
            step++;
            
        }

        return -1;

    }
};
// @lc code=end

int main(){


    Solution s;
    vector<vector<int>> grid={{0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0},{0,1,0,0,1,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0},{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},{0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0},{1,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,0,1,1},{0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,1,0,0,0,0},{0,0,0,0,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,0},{1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,1,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}};
    cout << s.minimumMoves(grid);
}