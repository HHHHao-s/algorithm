#include "s.h"
/*
 * @lc app=leetcode.cn id=2781 lang=cpp
 *
 * [2781] 最长合法子字符串的长度
 */

// @lc code=start
class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n = word.size();
        
        unordered_set<string> fb;
        for(auto &s:forbidden){
            fb.insert(s);
        }


        int left = 0;
        int ans = 0;
        for(int right=0;right<n;right++){
            for(int i=right;i>=left && i>right-10;i--){
                if(fb.count(word.substr(i, right-i+1))){
                    left = i;
                    break;
                }
            }
            ans = max(ans, right-left+1);

        }
        return ans;
        
    }
};
// @lc code=end

