#include "s.h"
/*
 * @lc app=leetcode.cn id=2262 lang=cpp
 *
 * [2262] 字符串的总引力
 */

// @lc code=start
class Solution {
public:
    long long appealSum(string s) {
        
        unordered_map<int,int> last;
        long long cur = 0;
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(last.count(s[i])==0){
                cur += i+1;
                ans += cur;
                last[s[i]] = i;
            }else{
                cur += i-last[s[i]];
                ans += cur;
                last[s[i]] = i;
            }
        }
        return ans;

    }
};
// @lc code=end

