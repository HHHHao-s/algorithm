#include "s.h"
/*
 * @lc app=leetcode.cn id=858 lang=cpp
 *
 * [858] 镜面反射
 */

// @lc code=start
class Solution {
private:
    enum Dir{
            LEFT,DOWN,RIGHT,UP
    };
    

public:
    int mirrorReflection(int p, int q) {

        int g = gcd(p,q);
        int k = p/g;// 步数
        int right = k%2;
        int up = (k*q/p)%2;

        if(right && up){
            return 1;
        }
        if(!right && up){
            return 2;
        }
        if(right && !up){
            return 0;
        }

        return -1;
    }
};
// @lc code=end

