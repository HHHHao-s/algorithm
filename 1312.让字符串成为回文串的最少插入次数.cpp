#include "s.h"
/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }

        for(int i=n;i-->0;){
            char c1 = s[i];
            for(int j=i+1;j<n;j++){
                char c2 = s[j];
                if(c1 == c2){
                    if(j-i==1){
                        dp[i][j] = 2;
                    }else{
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return n-dp[0][n-1];

    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.minInsertions("mbadm");


    return 0;
}