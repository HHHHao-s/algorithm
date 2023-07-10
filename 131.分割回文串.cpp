#include "s.h"
/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:

    int n;
    vector<string> cur;
    vector<vector<string>> ret;
    vector<vector<int>> dp; // i 到 j是不是回文


    bool isHuiwen(const string& s, int i, int j){
        if(dp[i][j]==1 || i==j){
            return true;
        }else if(dp[i][j]==0 || i<0 || j>=n){
            return false;
        }
        return dp[i][j] = (s[i] == s[j]  && (j-i <=1 || isHuiwen(s,i+1,j-1)));
    }


    void dfs(string &s , int first){
        if(first==n){
            ret.push_back(cur);
            return;
        }
        for(int i=first;i<n;i++){
            if(isHuiwen(s, first,i)){
                cur.push_back(s.substr(first,i-first+1));
                dfs(s, i+1);
                cur.pop_back();
            }
        }

    }


    vector<vector<string>> partition(string s) {
        n = s.size();
        dp = vector<vector<int>>(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        dfs(s, 0);
        return ret;

    }
};
// @lc code=end

int main(){

    Solution s;

    print2d(s.partition("ababbaba"));

    return 0;
}
