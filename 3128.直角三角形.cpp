#include "s.h"
/*
 * @lc app=leetcode.cn id=3128 lang=cpp
 *
 * [3128] 直角三角形
 */

// @lc code=start
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cnt(m, vector<int>(n, 0)) ,cnt2(m, vector<int>(n, 0));

        for(int i=0;i<m;i++){
            cnt[i][0] = grid[i][0];
            for(int j=1;j<n;j++){
                cnt[i][j] = cnt[i][j-1] + grid[i][j];
            }
        }

        for(int i=0;i<n;i++){
            cnt2[0][i] = grid[0][i];
            for(int j=1;j<m;j++){
                cnt2[j][i] = cnt2[j-1][i] + grid[j][i];
            }
        }
        long long ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=1){
                    continue;
                }
                long long  l = cnt[i][j] -1;
                long long r = cnt[i][n-1] - cnt[i][j];
                long long u = cnt2[i][j] - 1;
                long long d = cnt2[m-1][j] - cnt2[i][j];
                ans += l*u + r*u + r*d+l*d;
            }
            
        }

        return ans;



    }
};
// @lc code=end

