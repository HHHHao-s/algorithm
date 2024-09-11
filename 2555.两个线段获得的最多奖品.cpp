#include "s.h"
/*
 * @lc app=leetcode.cn id=2555 lang=cpp
 *
 * [2555] 两个线段获得的最多奖品
 */

// @lc code=start
class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        int l = 0;

        int mx =0;
        vector<int> dp(n);
        int ans =0 ;
        for(int r=0;r<n;r++){

            while(prizePositions[r]-prizePositions[l]>k){
                mx = max(dp[l], mx);
                
                l++;
            }
            int sz=  r-l+1;
            ans = max(mx+sz, ans);
            dp[r] = sz;

        }
        return ans;
        

    }
};
// @lc code=end

