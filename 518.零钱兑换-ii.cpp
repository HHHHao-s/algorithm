#include "s.h"
/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount,const vector<int>& coins) {

        int n = coins.size();

        vector<int> dp(amount+1);

        dp[0] = 1;

        for(int coin: coins){
            for(int i=coin;i<=amount;i++){
                dp[i] += dp[i-coin];
            }
        }
        

        return dp[amount];

    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.change(5,{1,2,5});

}