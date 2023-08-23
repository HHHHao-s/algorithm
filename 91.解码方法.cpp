#include "s.h"
/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n+1);
        
        dp[0] = 1;
        dp[1] = s[0]!='0';

        for(int i=2;i<=n;i++){
            char c = s[i-1];
            if(c!='0'){
                dp[i] += dp[i-1];
            }
            char last_c = s[i-2];
            if(last_c=='1' ||(last_c=='2' && c<='6')){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.numDecodings("06");

    return 0;
}