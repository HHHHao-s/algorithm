#include "s.h"
/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        string stk;
        vector<int> vis(26), num(26);
        for(char c:s){
            num[c-'a']++;
        }

        for(char c:s){
            if(!vis[c-'a']){
                while(!stk.empty() && stk.back()>c && num[stk.back()-'a']>0){
                    stk.pop_back();
                    vis[stk.back()-'a']=0;
                }
                stk.push_back(c);
                vis[c-'a']=1;
                
            }
            num[c-'a']--;          
        }
        return stk;

    }
};
// @lc code=end

