#include "s.h"
/*
 * @lc app=leetcode.cn id=2328 lang=cpp
 *
 * [2328] 网格图中递增路径的数目
 */

// @lc code=start
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo (m ,vector<int>(n, -1));

        int dirx[ 4] = {0,1,0,-1};
        int diry[4] = {1,0,-1,0}; 
        constexpr int MOD = 1e9+7;
        auto dfs = [&](auto &&dfs, int x, int y) -> long long{
            if(memo[x][y]!=-1){
                return memo[x][y];
            }
            long long ret=1;
            for(int i=0;i<4;i++){
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if(nx <0 || nx>=m || ny<0 || ny>=n){
                    continue;
                }
                if(grid[nx][ny] > grid[x][y]){
                    ret =( ret + dfs(dfs, nx, ny))%MOD;
                }

            }
            memo[x][y] = ret;
            return ret;
        };
        long long ret = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ret = (ret + dfs(dfs, i,j))%MOD;
            }
        }
        if(ret < 0){
            ret +=MOD;
        }
        return ret;


    }
};
// @lc code=end

