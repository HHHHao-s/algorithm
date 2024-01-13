#include "s.h"
/*
 * @lc app=leetcode.cn id=960 lang=cpp
 *
 * [960] 删列造序 III
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();

        // vector<vector<int>> dp(n, vector<int>(strs[0].size()));
        vector<int> dp(strs[0].size(), 1);

        dp[0] = 1;

        for(int i=1;i<strs[0].size();i++){
            for(int j=0;j<i;j++){
                bool can = 1;
                
                for(int k=0;k<n;k++){
                    if(strs[k][i]<strs[k][j]){
                        can=0;
                        break;
                    }
                }
                if(can){
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
            
        }
        int ans = INT_MAX;
        for(int i=0;i<strs[0].size();i++){
            ans = min(ans, (int)strs[0].size()- dp[i]);
        }
        return ans;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<string> strs={
        "babca","bbazb"
    };
    cout << s.minDeletionSize(strs);
}