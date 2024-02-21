#include "s.h"
/*
 * @lc app=leetcode.cn id=2088 lang=cpp
 *
 * [2088] 统计农场中肥沃金字塔的数目
 */

// @lc code=start
class Solution {
private:
    int count(vector<vector<int>> & grid){
        vector<vector<int>> dp = grid;

        int m = grid.size(),n = grid[0].size();
        int ans = 0;
        for(int i=m;i-->0;){
            for(int j=n;j-->0;){
                if(grid[i][j]==0){
                    continue;
                }
                int valid_biggest=10000;
                for(int k=-1;k<=1;k++){
                    if(i+1>=m || j+k>=n || j+k<0){
                        valid_biggest=10000;
                        break;
                    }else{
                        valid_biggest = min(valid_biggest, dp[i+1][j+k]);
                    }
                }
                if(valid_biggest!=10000){
                    dp[i][j] = valid_biggest+1;
                    ans += valid_biggest;
                }
            }
        }
        return ans;
    }

public:
    int countPyramids(vector<vector<int>>& grid) {
        
        int a1 = count(grid);
        reverse(grid.begin(), grid.end());
        
        int a2 = count(grid);
        cout << a1 << ' ' << a2;
        return a1+a2;

    }
};
// @lc code=end

