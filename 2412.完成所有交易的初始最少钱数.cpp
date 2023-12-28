#include "s.h"
/*
 * @lc app=leetcode.cn id=2412 lang=cpp
 *
 * [2412] 完成所有交易的初始最少钱数
 */

// @lc code=start
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {

        long long mx_cost = 0 ;
        long long dif = 0;
        long long mi_cost = 0;
        for(auto & ts: transactions){
            if(ts[0]>ts[1]){
                dif+=ts[0]-ts[1];
                mi_cost = max(mi_cost, (long long)ts[1]);               
            }else{
                mx_cost = max(mx_cost, (long long)ts[0]);
            }
            
            
            
            
        }
        return dif+ max(mi_cost, mx_cost);

    }
};
// @lc code=end

