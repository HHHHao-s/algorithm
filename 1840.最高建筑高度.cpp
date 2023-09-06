#include "s.h"
/*
 * @lc app=leetcode.cn id=1840 lang=cpp
 *
 * [1840] 最高建筑高度
 */

// @lc code=start
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        sort(restrictions.begin(), restrictions.end());

        if(restrictions.back()[0]!=n){
            restrictions.push_back({n,n-1});
        }

        int m = restrictions.size();

        for(int i=1;i<m;i++){
            restrictions[i][1] = min(restrictions[i][1],restrictions[i-1][1] + restrictions[i][0]-restrictions[i-1][0]);
        }

        for(int i=m-1;i-->0;){
            restrictions[i][1] = min(restrictions[i][1],restrictions[i+1][1] + restrictions[i+1][0]-restrictions[i][0]);
        }

        int ans=0;

        for(int i=0;i<m-1;i++){
            ans = max(ans, ((restrictions[i+1][0]-restrictions[i][0])+restrictions[i+1][1]+restrictions[i][1])/2);
        }
        return ans;
    }
};
// @lc code=end

