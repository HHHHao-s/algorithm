#include "s.h"
/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(const vector<int>& coins, int amount) {

        int n = coins.size();

        vector<int> dp(amount+1, amount+1);

        dp[0] = 0;

        for(int i=1;i<=amount;i++){
            int tmp=dp[i];
            for(int j=0;j<n;j++){
                if(coins[j]<=i){
                    tmp = min(tmp, dp[i-coins[j]]+1);
                }
            }
            dp[i] = tmp;
        }
        return dp[amount]>amount?-1:dp[amount];
        
    }
};
// @lc code=end

int main(){

    Solution s;
    cout << s.coinChange({265,398,46,78,52},7754);


    return 0;
}