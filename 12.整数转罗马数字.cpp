#include "s.h"
/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:

   

    string intToRoman(int num) {

    map<int,string> m={
        {1000,"M"},
        {900,"CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };


    string ans;

    
    for(auto i=m.rbegin();i!=m.rend();i++){
        int n = num/i->first;
        for(int j=0;j<n;j++){
            ans.append(i->second);
            
        }
        num%= i->first;
    }
    
    return ans;


    }
};
// @lc code=end

