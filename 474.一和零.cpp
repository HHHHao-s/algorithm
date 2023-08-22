#include "s.h"
/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:

    pair<int,int> countMN(string s){
        int ret[2];
        ret[0]=0;
        ret[1]=0;

        for(char c:s){
            ret[c-'0']++;
        }
        return {ret[0], ret[1]}; // 0,1
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0] = 0;

        for(auto s:strs){
            auto [_m,_n] = countMN(s);
            for(int i=m+1;i-->0;){
                for(int j=n+1;j-->0;){
                    if(i>=_m && j>=_n){
                        dp[i][j] = max({dp[i-_m][j-_n]+1,dp[i][j]});
                    }
                }
            }

        }
        return dp[m][n];
    }
};
// @lc code=end

int main(){

    Solution s;
    vector<string> strs = {
        "10", "0001", "111001", "1", "0"
    };

    cout << s.findMaxForm(strs, 5,3);


    return 0;
}