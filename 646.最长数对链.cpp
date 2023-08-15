#include "s.h"
/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        using p = pair<int,int>;

        sort(pairs.begin(), pairs.end());

        vector<int> dp;

        int n = pairs.size();

        
        for(int i=0;i<n;i++){
            int x1 = pairs[i][0], x2 = pairs[i][1];

            if(dp.size()==0||x1>dp.back()){
                dp.push_back(x2);
                continue;
            }

            int pos = lower_bound(dp.begin(), dp.end(), x1)-dp.begin();
            
            dp[pos] = min(dp[pos], x2);

        }

        return dp.size();

    }
};
// @lc code=end

