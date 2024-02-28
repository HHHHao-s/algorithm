#include "s.h"
/*
 * @lc app=leetcode.cn id=2746 lang=cpp
 *
 * [2746] 字符串连接删减字母
 */

// @lc code=start
class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        vector<vector<int>> dp(26, vector<int>(26, INT_MAX));

        dp[words[0].front()-'a'][words[0].back()-'a'] = words[0].size();
        
        
        for(int i=1;i<words.size();i++){
            string &s = words[i];
            int l = s.front()-'a', r=s.back()-'a';

            vector<vector<int>> ndp(26, vector<int>(26, INT_MAX));
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    if(dp[j][k]!=INT_MAX){
                        if(k==l){
                            ndp[j][r] =min(ndp[j][r], dp[j][k] + (int)s.size()-1) ;
                        }else{
                            ndp[j][r] =min(ndp[j][r], dp[j][k] + (int)s.size()) ;
                        }
                        if(r==j){
                            ndp[l][k] =min(ndp[l][k], dp[j][k] + (int)s.size()-1) ;
                        }else{
                            ndp[l][k] = min(ndp[l][k], dp[j][k] + (int)s.size()) ;
                        }
                    }
                }
            }
            dp = ndp;

        }
        int ans = INT_MAX;
        for(int j=0;j<26;j++){
            for(int k=0;k<26;k++){
                if(dp[j][k]!=0){
                    ans = min(dp[j][k], ans);
                }
            }
        }
        return ans;

        
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<string> words= {"ab","cab","aa"};
    cout << s.minimizeConcatenatedLength(words);
}