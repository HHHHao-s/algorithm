#include "s.h"
/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        sort(piles.begin(),piles.end());

        long long l = 1;
        long long r = 1e9+1;

        while(l<=r){

            long long mid = (l+r)/2;

            long long t = 0;
            for(auto pile: piles){

                t+= (pile+mid-1)/mid;
            } 
            if(t<=h){
                r = mid-1;
            }else{
                l = mid+1;
            }
            
        }

        return r+1;

    }
};
// @lc code=end

