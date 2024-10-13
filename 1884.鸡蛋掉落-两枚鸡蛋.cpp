#include "s.h"
/*
 * @lc app=leetcode.cn id=1884 lang=cpp
 *
 * [1884] 鸡蛋掉落-两枚鸡蛋
 */

// @lc code=start
class Solution {
public:
    int twoEggDrop(int n) {
        if(n==1 || n==2){
            return n;
        }
        int l=1,r=n;

        while(l<=r){

            int t = (l+r)/2;
            
            if(t*(t+1)/2 >= n){
                // can
                r = t-1;

            }else{
                l = t+1;
            }
        }

        return r+1;

    }
};
// @lc code=end

