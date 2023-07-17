#include "s.h"
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:



    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int max_profit=0, low=0, hi=0;

        for(int i=1;i<prices.size();i++){
            if(prices[i]<prices[low]){
                low = i;
                hi = i;
                
            }else if(prices[i]>prices[hi] && i > low){
                hi = i;
                int x = prices[hi] - prices[low];
                max_profit = x > max_profit?x:max_profit;
            }
        }
        
        return max_profit;

    }
};
// @lc code=end

