#include "s.h"
/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        if(n>m){
            return 0;
        }else if(n==m){
            return s.compare(t) ==0;
        }
        // vector<vector<long long>> dp(m+1, vector<long long>(n+1,0));
        // dp[0][0] = 1;
        
        // for(int i=1;i<=m;i++){
        //     dp[i][0] = 1;
        // }

        vector<long long> each_item(n+1,0);
        each_item[0] = 1;

        for(int i=1;i<=m;i++){
            char c1 = s[i-1];
            vector<long long> tmp(n+1,0);
            tmp[0] = 1;
            for(int j=1;j<=n&&j<=i;j++){
                char c2 = t[j-1];
                if(c1==c2){
                    if(j!=i){
                        if(each_item[j-1]<~(1ll<<63)-each_item[j]){
                            tmp[j] = each_item[j-1]+each_item[j]; // the first time match or match again
                        }
                        
                    }else{
                        tmp[j] = each_item[j-1];
                    }
                     
                }else{
                    tmp[j] = each_item[j];
                }
                
            }
            each_item = std::move(tmp);
        }
        return each_item[n];
    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.numDistinct("rararr", "rar");


    return 0;
}