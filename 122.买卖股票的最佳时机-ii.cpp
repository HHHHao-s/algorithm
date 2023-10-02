#include "s.h"
/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int a = -prices[0];
        int b = 0;

        for(int i=1;i<n;i++){
            int tem_a = a;
            int tem_b = b;

            a = max(tem_a, tem_b-prices[i]);
            b =  max(tem_a+prices[i] ,tem_b);

        }
        return b;

    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int> prices={
        3,2,6,5,0,3
    };
    cout << s.maxProfit(prices);

    return 0;
}