#include "s.h"
/*
 * @lc app=leetcode.cn id=1771 lang=cpp
 *
 * [1771] 由子序列构造的最长回文串的长度
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        auto s = word1+word2;

        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        for(int i=0;i<s.size();i++){
            dp[i][i] = 1;
        }
        int ans=0;
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i+1;j<s.size();j++){
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1]+2;
                    if(i<word1.size() && j>=word1.size()){
                        ans = max(ans, dp[i][j]);
                    }
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }

            }
        }
        return ans;
        

    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.longestPalindrome("ceebeddc", "d");
}