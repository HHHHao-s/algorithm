#include "s.h"
/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
private:
    int find(vector<int>& nums , int l, int r){
        if(r-l<2){
            return -1;
        }
        int mid = (l+r)/2;
        int ml = nums[mid-1];
        int mr= nums[mid+1];
        int mm = nums[mid];
        if(ml<mm && mm<mr){
            
                return find(nums, mid,r);
            
        }else if(ml>mm && mm>mr){
            
            return find(nums, l,mid);
            
        }else if(mm<ml && mm<mr){
            int ret = find(nums, l, mid);
            if(ret!=-1){
                return ret;
            }else{
                return find(nums, mid, r);
            }
        }else{
            return mid;
        }
        
    }

public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int r= nums.size()-1;
        if(r==l){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[r]>nums[r-1]){
            return r;
        }
        return find(nums, l,r);
        
    }
};
// @lc code=end

