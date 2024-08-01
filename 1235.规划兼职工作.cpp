#include "s.h"
/*
 * @lc app=leetcode.cn id=1235 lang=cpp
 *
 * [1235] 规划兼职工作
 */

// @lc code=start
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int,int, int>> each(n);

        for(int i=0;i<n;i++){
            each[i] = {endTime[i], startTime[i], profit[i]};
        }
        map<int,int> dp;
        dp[0] = 0;
       


        sort(each.begin(), each.end());
        int ret = 0;
        for(auto [end, start, p] : each){

            auto last = --dp.upper_bound(start);


            dp[end] = max({ret,dp[end], last->second + p} );
            ret = max(dp[end], ret);

        }

        return ret;


    
    
    }

};
// @lc code=end

