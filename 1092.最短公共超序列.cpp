#include "s.h"
/*
 * @lc app=leetcode.cn id=1092 lang=cpp
 *
 * [1092] 最短公共超序列
 */

// @lc code=start
class Solution {
public:
    /*
    string shortestCommonSupersequence(string str1, string str2) {
        
        int m = str1.size(),n=str2.size();
        vector<vector<string>> dp(m+1,vector<string>(n+1,""));
        for(int i=1;i<=m;i++){
            char c1 = str1[i-1];
            for(int j=1;j<=n;j++){
                char c2 = str2[j-1];
                if(c1==c2){
                    if(dp[i-1][j-1].size()+1 > dp[i-1][j].size() && dp[i-1][j-1].size()+1 > dp[i][j-1].size()){
                        dp[i][j] =  dp[i-1][j-1] +c1;
                    }else{
                        if(dp[i-1][j].size()>dp[i][j-1].size()){
                            dp[i][j] = dp[i-1][j];
                        }else{
                            dp[i][j] = dp[i][j-1];
                        }
                    }
                }else{
                    if(dp[i-1][j].size()>dp[i][j-1].size()){
                        dp[i][j] = dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        string &same =dp[m][n];
        cout << same << endl;
        string ans;
        auto it1 = str1.begin();
        auto it2 = str2.begin();
        for(char c:same){
            while(it1!=str1.end() && c!=*it1){
                ans.push_back(*it1);
                it1++;
            }
            while(it2!=str2.end() && c!=*it2){
                ans.push_back(*it2);
                it2++;
            }
            ans.push_back(c);
            it1++;
            it2++;
        }
        while(it1!=str1.end()){
            ans.push_back(*it1);
            it1++;
        }
        while(it2!=str2.end()){
            ans.push_back(*it2);
            it2++;
        }
        return ans;
    }
    */
    string shortestCommonSupersequence(string s, string t) {
        
        int m = s.size(),n=t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++) dp[i][0] = i;
        for(int j=0;j<=n;j++) dp[0][j] = j;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;

                }else{
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
                }
            }
        }
        
        int i=m-1;
        int j=n-1;
        string ans;
        while(i>=0&&j>=0){

            if(s[i]==t[j]){
                ans.push_back(s[i]);
                i--;
                j--;
                continue;
            }else{
                if(dp[i+1][j+1]==dp[i][j+1]+1){
                    // 说明dp[iti][itj+1]更小，那么这时加上s[i]
                    ans+=s[i];
                    i--;
                }else{
                    ans+=t[j];
                    j--;
                }
            }


        }
        reverse(ans.begin(),ans.end());
        return s.substr(0, i + 1) + t.substr(0, j + 1) + ans;

        
    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.shortestCommonSupersequence("abac","cab") <<endl;
    cout << s.shortestCommonSupersequence("aaaaa","aaaaaa") <<endl;
    cout << s.shortestCommonSupersequence("babadadcbcbabac","bcdbadbabb") <<endl;
}