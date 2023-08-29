#include "s.h"
/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        vector<vector<int>> vis(m, vector<int>(n));

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    ret[i][j]=0;
                    vis[i][j]=1;
                    q.push({i,j});
                }
                
            }
        }

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nx = x+dirs[k][0];
                int ny = y+dirs[k][1];

                if(nx<0 || nx >=m || ny<0 || ny>=n || vis[nx][ny]){
                    continue;
                }

                ret[nx][ny] = ret[x][y]+1;
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }


        }

        return ret;
    }
};
// @lc code=end

int main(){

    Solution s;

    vector<vector<int>> mat= {
        {0,1,0},
        {0,1,0},
        {0,1,0},
        {1,1,1},
        {1,1,1}
    };

    print2d(s.updateMatrix(mat));

    return 0;
}