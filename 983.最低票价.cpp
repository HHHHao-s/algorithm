#include "s.h"
/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */

// @lc code=start
class Solution {
public:
    int mincostTickets(const vector<int>& days,const vector<int>& costs) {

        int n = days.size();

        // int max_day = days[n-1];

        vector<int> dp(n+1);
        int cost1 = costs[0];
        int cost2 = costs[1];
        int cost3 = costs[2];

        dp[0] = 0;

        for(int i=1;i<=n;i++){
            int day = days[i-1];

            int last_7=i-2;
            for(;last_7>-1 && days[last_7]>day-7;last_7--);
            
            int last_30=last_7;

            for(;last_30>-1 && days[last_30]>day-30;last_30--);

            dp[i] = min({dp[i-1]+cost1, dp[last_7+1]+cost2,dp[last_30+1]+cost3});


        }

        return dp[n];
    }
};
// @lc code=end

int main(){

    Solution s;

    cout<< s.mincostTickets(
        {1,2,3,4,5,6,7,8,9,10,30,31},
        {2,7,15}
    );


    return 0;
}