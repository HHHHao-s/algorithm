#include "s.h"
/*
 * @lc app=leetcode.cn id=1016 lang=cpp
 *
 * [1016] 子串能表示从 1 到 N 数字的二进制串
 */

// @lc code=start
class Solution {
public:
    bool queryString(string s, int n) {
        
        if(n>1e6){
            return false;
        }

        vector<int> have(n+1,0);

        for(int i=0;i<s.size();i++){
            
            long long cur = 0;

            for(int j=0;j<32;j++){

                int l = i-j;
                if(l<0){
                    break;
                }

                cur += ((1&(s[l]-'0'))<<j) ;
                if(cur>n){
                    break;
                }
                have[cur]=1;

            }
        }
        for(int i=1;i<=n;i++){
            if(have[i]==0){
                return false;
            }
        }
        return true;

    }
};
// @lc code=end

