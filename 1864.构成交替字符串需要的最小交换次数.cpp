#include "s.h"
/*
 * @lc app=leetcode.cn id=1864 lang=cpp
 *
 * [1864] 构成交替字符串需要的最小交换次数
 */

// @lc code=start
class Solution {
public:
    int minSwaps(string s) {
        int zeros=0;
        int ones=0;
        int n= s.size();
        for(char c :s){
            if(c=='0'){
                zeros++;
            }else if(c=='1'){
                ones++;
            }
        }
        int diff = zeros-ones>=0?zeros-ones:ones-zeros;
        if(diff>=2){
            return -1;
        }
        int ans=INT_MAX;
        int d1 = 0;
        if(zeros==(n+1)/2 && ones==n/2){
            for(int i=0;i<n;i++){
            
                // 01010
                if(s[i]-'0' != i%2){
                    d1++;
                }
            
            }
            ans = min(ans, d1/2);
        }
        
        if(ones ==(n+1)/2 && zeros==n/2){
            int d2=0;
            for(int i=0;i<n;i++){

                // 1010
                if(s[i]-'0' == i%2){
                    d2++;
                }
                
            }
            ans = min(ans, d2/2);
        }
        
        return ans==INT_MAX?-1:ans;


    }
};
// @lc code=end

