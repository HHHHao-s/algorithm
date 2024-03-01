#include    "s.h"
/*
 * @lc app=leetcode.cn id=959 lang=cpp
 *
 * [959] 由斜杠划分区域
 */

// @lc code=start
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> slice(n, vector<vector<int>>(n ,vector<int>(4,0)));
        int ans = 0;

        

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<4;k++){
                    if(!slice[i][j][k]){
                        ans++;
                        queue<tuple<int,int,int>> q;
                        q.push({i,j,k});
                        slice[i][j][k]=1;
                        while(!q.empty()){
                            auto [x,y,z] = q.front();
                            q.pop();
                            if(z==0){
                                if(grid[x][y]!='\\' && !slice[x][y][1]){
                                    slice[x][y][1] = 1;
                                    q.push({x,y,1});
                                }
                                if(grid[x][y]!='/' && !slice[x][y][2]){
                                    slice[x][y][2]=1;
                                    q.push({x,y,2});
                                }
                                if(y-1>=0 && !slice[x][y-1][3]){
                                    slice[x][y-1][3] =1;
                                    q.push({x,y-1,3});
                                }
                            }else if(z==1){
                                if(grid[x][y]!='\\' && !slice[x][y][0]){
                                    slice[x][y][0] = 1;
                                    q.push({x,y,0});
                                }
                                if(grid[x][y]!='/' && !slice[x][y][3]){
                                    slice[x][y][3]=1;
                                    q.push({x,y,3});
                                }
                                if(x-1>=0 && !slice[x-1][y][2]){
                                    slice[x-1][y][2] =1;
                                    q.push({x-1,y,2});
                                }
                            }else if(z==2){
                                if(grid[x][y]!='\\' && !slice[x][y][3]){
                                    slice[x][y][3] = 1;
                                    q.push({x,y,3});
                                }
                                if(grid[x][y]!='/' && !slice[x][y][0]){
                                    slice[x][y][0]=1;
                                    q.push({x,y,0});
                                }
                                if(x+1<n && !slice[x+1][y][1]){
                                    slice[x+1][y][1] =1;
                                    q.push({x+1,y,1});
                                }
                            }else if(z==3){
                                if(grid[x][y]!='\\' && !slice[x][y][2]){
                                    slice[x][y][2] = 1;
                                    q.push({x,y,2});
                                }
                                if(grid[x][y]!='/' && !slice[x][y][1]){
                                    slice[x][y][1]=1;
                                    q.push({x,y,1});
                                }
                                if(y+1<n && !slice[x][y+1][0]){
                                    slice[x][y+1][0] =1;
                                    q.push({x,y+1,0});
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<string> grid = {" /","/ "};
    cout << s.regionsBySlashes(grid);
}