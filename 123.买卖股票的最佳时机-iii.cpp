#include "s.h"
/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int n = prices.size();

        int buy1=-prices[0], sale1=0;
        int buy2=-prices[0], sale2=0;

        for(int i=1;i<n;i++){
            int tmp1 = buy1;
            int tmpsale1= sale1;
            int tmp2 = buy2;
            buy1 = max(buy1, -prices[i]);
            sale1 = max(tmp1+prices[i],sale1);
            buy2 = max(buy2, tmpsale1-prices[i]);
            sale2 = max(tmp2+prices[i], sale2);
        }
        return sale2;

    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.maxProfit({3,3,5,0,0,3,1,4});

    return 0;
}