#include "s.h"
/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int l = 0,r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(n-mid==citations[mid]){
                return n-mid;
            }else if(n-mid>citations[mid]){
                l=mid+1;
            }else{
                r=mid-1;
            }

        }
        return 0;
    }
};
// @lc code=end

