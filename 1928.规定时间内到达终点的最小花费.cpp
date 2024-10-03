#include "s.h"
/*
 * @lc app=leetcode.cn id=1928 lang=cpp
 *
 * [1928] 规定时间内到达终点的最小花费
 */

// @lc code=start
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<int>> f(maxTime+1, vector<int>(n, INT_MAX/2));
        f[0][0] = passingFees[0];

        for(int t=1;t<=maxTime;t++){

            for(auto &edge: edges){

                int x = edge[0],y=edge[1],nt=edge[2];

                if(t-nt>=0){
                    f[t][x] = min(f[t][x], f[t-nt][y]+passingFees[x]);
                    f[t][y] = min(f[t][y], f[t-nt][x]+passingFees[y]);
                }

            }

        }

        int ans = INT_MAX/2;
        for (int t = 1; t <= maxTime; ++t) {
            ans = min(ans, f[t][n - 1]);
        }
        return ans == INT_MAX/2 ? -1 : ans;



    }
};
// @lc code=end

