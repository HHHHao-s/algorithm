#include "s.h"
/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k,const vector<int>& prices) {
        vector<int> dp(2*k,0);
        vector<int> tmp;
        for(int i=0;i<k;i++){
            dp[2*i] = -prices[0];
            
        }

        int n = prices.size();
        
        for(int i=1;i<n;i++){
            tmp = dp;
            int price = prices[i];
            dp[0] = max(tmp[0], -price);
            dp[1] = max(tmp[1], price+tmp[0]);

            for(int j=1;j<k;j++){
                dp[2*j] = max(tmp[2*j],tmp[2*j-1]-price);
                dp[2*j+1] = max(tmp[2*j+1], tmp[2*j]+price);
            }

        }

        return dp[2*k-1];
        
    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.maxProfit(1,{3,2,6,5,0,3});

    return 0;
}