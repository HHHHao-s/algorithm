#include "s.h"
/*
 * @lc app=leetcode.cn id=2530 lang=cpp
 *
 * [2530] 执行 K 次操作后的最大分数
 */

// @lc code=start
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> p;
        for(int x:nums){
            p.push(x);
        }
        long long sum=0;
        for(int i=0;i<k;i++){
            int top = p.top();
            p.pop();
            sum+=top;
            p.push((top+2)/3);

        }
        return sum;
    }
};
// @lc code=end

