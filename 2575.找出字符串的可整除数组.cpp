#include "s.h"
/*
 * @lc app=leetcode.cn id=2575 lang=cpp
 *
 * [2575] 找出字符串的可整除数组
 */

// @lc code=start
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ret;
        long long t=0;
        for(char c: word){
            t = (t*10+c-'0')%m;
            if(t%m==0){
                ret.push_back(1);
                t= 0;
            }else{
                ret.push_back(0);
            }
        }
        return ret;
    }
};
// @lc code=end

