#include "s.h"
/*
 * @lc app=leetcode.cn id=1278 lang=cpp
 *
 * [1278] 分割回文串 III
 */

// @lc code=start
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        if(n==k) return 0;

        vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(n+1,vector<int>(n+1,INT_MAX)));

        for(int i=0;i<n;i++){
            dp[1][i][i]=0;
        }

        for(int j=n;j-->0;){
            for(int i=j+1;i<n;i++){
                if(i-j>1){
                    if(s[j]==s[i]){
                        dp[1][j][i] = dp[1][j+1][i-1];
                    }else{
                        dp[1][j][i] = dp[1][j+1][i-1]+1;
                    }
                }else{
                    if(s[j]==s[i]){
                        dp[1][j][i] = 0;
                    }else{
                        dp[1][j][i] = 1;
                    }
                }
                
            }
        }

        for(int i=2;i<=k;i++){
            for(int j=n-i;j>=0;j--){
                int o=1;
                for(int l=j+i-1;l<n;l++){
                    for(int ll=j+o-1;l-ll>=i-o;ll++){
                        dp[i][j][l] = min(dp[i][j][l], dp[o][j][ll]+dp[i-o][ll+1][l]);
                    }
                   
                
                }               
            }
        }
        return dp[k][0][n-1];

    }   
};
// @lc code=end

int main(){

    Solution s;

    cout << s.palindromePartition("adfasdf", 5);
}