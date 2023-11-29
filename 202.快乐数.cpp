#include "s.h"
/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> each;
        while(n!=1){
            if(each.count(n)){
                break;
            }           
            each.insert(n);
            int tn=n;
            int nx=0;
            while(tn){
                nx+=(tn%10)*(tn%10);
                tn/=10;
            }
            n=nx;
        }
        return n==1;
    }
};
// @lc code=end

