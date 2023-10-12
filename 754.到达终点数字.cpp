#include "s.h"
/*
 * @lc app=leetcode.cn id=754 lang=cpp
 *
 * [754] 到达终点数字
 */

// @lc code=start
class Solution {
private:


public:
    int reachNumber(int target) {

        target = abs(target);
        int k=0;
        while(target>=0){
            k++;
            target-=k;

        }
        if(target%2==0){
            return k;
        }else{
            // 奇数情况
            if(k%2==0){
                // k是偶数
                // 因为target是奇数
                // k+1 是奇数
                return k+1;
            }else{
                // k是奇数
                // 因为target是奇数
                // k+1+k+2是奇数
                return k+2;
            }
        }
        return -1;

    }
};
// @lc code=end
