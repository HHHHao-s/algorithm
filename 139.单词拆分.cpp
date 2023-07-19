#include "s.h"
/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s,const vector<string>& wordDict) {

        vector<bool> dp(s.size()+1,false);
        dp[0] = true;// 0 长度是true
        size_t max_length=INT_MAX;
        unordered_set<string> m;
        for(int i=0;i<wordDict.size();i++){
            m.insert(wordDict[i]);
            max_length = min(max_length, wordDict[i].size());
        }

        size_t n = s.size();



        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(dp[j]==true) continue;
                if(m.count(s.substr(i-1, j-i+1)) >0){
                    dp[j] = dp[i-1];
                }
            }
        }
        
        return dp[n];




    }
};
// @lc code=end

int main(){

    Solution s;
    cout << s.wordBreak("aaaaadogandog", {"a", "dog", "sand", "and", "cat"});


    return 0;
}