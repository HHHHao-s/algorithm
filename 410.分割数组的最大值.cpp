#include "s.h"
/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
private:
    bool test(vector<int>& nums, int k, int mx){

        int cnt = 0;
        
        int index=0;
        while(index<nums.size()){

            int cur = 0;
            cnt++;
            if(cnt>k){
                return false;
            }
            while(cur+nums[index]<= mx && index<nums.size()){
                cur+= nums[index];
                index++;

            }
            

        }
        return true;

    }

public:
    int splitArray(vector<int>& nums, int k) {
        

        int left = *max_element(nums.begin(), nums.end());
        int right = 1000000000;
        int ans = 0;

        while(left<=right){
            int mid = left+ (right-left)/2;
            if(test(nums, k, mid)){
                ans = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return ans;


    }
};
// @lc code=end

