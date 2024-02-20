#include "s.h"
/*
 * @lc app=leetcode.cn id=2430 lang=cpp
 *
 * [2430] 对字母串可执行的最大删除数
 */

// @lc code=start
class Solution {
public:
    int deleteString(string s) {
        
        vector<int> dp(s.size()+1, 0);

        int n = s.size();

        if (equal(s.begin() + 1, s.end(), s.begin())) // 特判全部相同的情况
            return n;

        vector<vector<int>> lcp(n+1, vector<int>(n+1));

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(s[i]==s[j]){
                    lcp[i][j] = lcp[i+1][j+1]+1;
                }
            }
        }

        for(int i=1;i<=n;i++){
            
            for(int j=0;j<i;j++){
                
                if(i-j<= n-i && (dp[j]!=0 || j==0) &&  lcp[j][i]>=i-j){
                    dp[i] =max(dp[j]+1, dp[i]);
                }
            }
        }
        int ret = 0;
        for(int i=1;i<=n;i++){
            ret = max(dp[i], ret);
        }
        return ret+1;


    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.deleteString("aaabaab");
}