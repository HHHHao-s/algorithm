#include "s.h"
/*
 * @lc app=leetcode.cn id=2513 lang=cpp
 *
 * [2513] 最小化两个数组中的最大值
 */

// @lc code=start
class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {

        if(divisor1==divisor2){
            int ans=  0;
            int whole = uniqueCnt1+uniqueCnt2;
            while(whole>divisor1){
                int groups = whole/divisor1;
                whole -= groups*(divisor1-1);

            }
        }

        long long g = gcd(divisor1, divisor2);
        long long mg = (long long)divisor1*divisor2/g;

        


    }
};
// @lc code=end

