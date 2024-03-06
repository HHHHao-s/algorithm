#include "s.h"
/*
 * @lc app=leetcode.cn id=2616 lang=cpp
 *
 * [2616] 最小化数对的最大差值
 */

// @lc code=start
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        if(p==0){
            return 0;
        }

        int l =0, r= nums.back() - nums[0];

        auto check = [&](int m){
            int p1= p;
            for(int i=1;i<nums.size();i++){
                if(nums[i]-nums[i-1] <= m){
                    p1--;
                    if(p1==0){
                        return true;
                    }
                    i++;
                }
            }
            return false;

        };

        while(l<=r){
            int mid = l+ (r-l)/2;
            if(check(mid)){
                r=mid-1;
            }else{
                l = mid+1;
            }
        }

        return r+1;

    }
};
// @lc code=end

