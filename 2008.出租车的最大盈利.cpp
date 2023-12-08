#include "s.h"
/*
 * @lc app=leetcode.cn id=2008 lang=cpp
 *
 * [2008] 出租车的最大盈利
 */

// @lc code=start
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        vector<long long> dp(n+1,0);

        auto f=[&](const vector<int> &a, const vector<int> &b){
            return a[1]<b[1];
        };

        sort(rides.begin(), rides.end(), f);
        int index=0;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            while(index<rides.size() && rides[index][1]==i){
                dp[i]=max(dp[i], dp[rides[index][0]]+rides[index][2]+i-rides[index][0]);
                index++;
            }

        }
        return dp[n];

    }
};
// @lc code=end

