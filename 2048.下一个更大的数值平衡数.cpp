#include "s.h"
/* 
* @lc app=leetcode.cn id=2048 lang=cpp
 *
 * [2048] 下一个更大的数值平衡数
 */

// @lc code=start
class Solution {
public:
    int nextBeautifulNumber(int n) {
        int tmpn=n;
        int digit=0;
        int high=0;
        vector<int> each_digit;
        while (tmpn)
        {
            each_digit.push_back(tmpn%10);
            
            digit++;
            tmpn/=10;
        }
        reverse(each_digit.begin(),each_digit.end());
        high=each_digit[0];
        bool want_min=0;
        if(high>digit){
            want_min=1;
            digit++;
        }

        if(!want_min){

        }
        
    }
};
// @lc code=end

