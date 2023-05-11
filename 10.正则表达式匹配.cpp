#include "s.h"
/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:

    

    bool isMatch(string s, string p) {

        bool dp[24][24] ={{true}};// dp[0][0] 表示空字符串可以匹配

        // dp[i][j] 表示p的前j个字符可以匹配s的前i个字符


        auto match = [&](int i,int j){
            if(i==0){
                return false;
            }
            if(p[j-1] == '.'){
                return true;
            }
            return p[j-1]==s[i-1];
        };

        int ns=s.size(), np=p.size();

        for(int i=0;i<=ns;i++){
            for(int j=1;j<=np;j++){
                if(p[j-1]=='*'){
                    
                    if(match(i,j-1)){
                        dp[i][j] |= dp[i-1][j] | dp[i][j-2]; // 要么前面的可以匹配，要么抛弃
                    }else{
                        dp[i][j] |= dp[i][j-2]; // 抛弃
                    }
                }else{
                    if(match(i,j))
                    dp[i][j] |= dp[i-1][j-1];
                }
            }
        }

        return dp[ns][np];

    }
};
// @lc code=end

