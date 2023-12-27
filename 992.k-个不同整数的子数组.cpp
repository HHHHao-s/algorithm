#include "s.h"
/*
 * @lc app=leetcode.cn id=992 lang=cpp
 *
 * [992] K 个不同整数的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nums1(n+1), nums2(n+1);

        int l1=0,l2=0,r=0;
        int k1=0,k2=0;
        int ans = 0;
        while(r<n){
            int num = nums[r];
            nums1[num]++;
            if(nums1[num]==1){
                
                k1++;
            }
            nums2[num]++;
            if(nums2[num]==1){
                
                k2++;
            }
            while(k1>k){
                if(nums1[nums[l1]]==1){
                    k1--;
                }
                nums1[nums[l1]]--;
                l1++;
                
            }
            while(k2>k-1){
                if(nums2[nums[l2]]==1){
                    k2--;
                }
                nums2[nums[l2]]--;
                l2++;
            }
            ans += l2-l1;
            r++;
        }   
        return ans;


    }
};
// @lc code=end

