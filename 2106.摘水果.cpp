#include "s.h"
/*
 * @lc app=leetcode.cn id=2106 lang=cpp
 *
 * [2106] 摘水果
 */

// @lc code=start
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        
        vector<long long > presum( 2e5+5);
        vector<int > fruit(2e5+5);
        for(auto&each:fruits){
            fruit[each[0]]=each[1]; 
        }
        for(int i=0;i<2e5+4;i++){
            presum[i+1] = presum[i] + fruit[i];
        }
        long long ret=0;
        for(int l=0;l<=k;l++){
            int r= max(0, k-2*l);
            long long tmp =0;
            if(startPos-l<0){   
                tmp += presum[startPos];
            }else{
                tmp += presum[startPos] - presum[startPos-l];
            }
            if(startPos+r+1>=2e5+5){
                tmp += presum[2e5+4]-presum[startPos];
            }else{
                tmp+= presum[startPos+r+1]-presum[startPos];
            }
            ret=  max(ret, tmp);
        }
        for(int r=0;r<=k;r++){
            int l = max(0, k-2*r);
            long long tmp =0;
            if(startPos-l<0){   
                tmp += presum[startPos];
            }else{
                tmp += presum[startPos] - presum[startPos-l];
            }
            if(startPos+r+1>=2e5+5){
                tmp += presum[2e5+4]-presum[startPos];
            }else{
                tmp+= presum[startPos+r+1]-presum[startPos];
            }
            ret=  max(ret, tmp);
        }
        return ret;
    }
};
// @lc code=end

