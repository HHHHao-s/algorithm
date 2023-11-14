#include "s.h"
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=  nums1.size();
        int n2 = nums2.size();

        

        int left = max(0,(n1+n2)/2-n2),right = min(n1, (n1+n2)/2);
        int cut = 0;
        while(left<=right){

            int m1 = (right+left)/2; // 第一个数组左边元素的个数
            int m2 = (n1+n2)/2 - m1;
            if(m2>0 && m1<n1 && nums1[m1]<nums2[m2-1]){
                left=m1+1;
            }else if(m1>0 && m2<n2 && nums1[m1-1]>nums2[m2]){
                right=m1-1;
            }else{
                cut = m1;
                break;
            }

        }

        int m1 = cut;
        int m2 = (n1+n2)/2 - m1;
        int ret1= m1==n1?INT_MAX:nums1[m1];
        int ret2= m2==n2?INT_MAX:nums2[m2];
        if((n1+n2)&1){

            return (double)min(ret1, ret2);
        }
        if(m1==0){
            return 1.0*(min(ret1, ret2)+nums2[m2-1])/2;
        }else if(m2==0){
            return 1.0*(min(ret1, ret2)+nums1[m1-1])/2;
        }
        
        return 1.0*(max(nums1[m1-1],nums2[m2-1])+min(ret1, ret2))/2;
    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int>v1 = {0,10};
    vector<int>v2 = {};
    cout << s.findMedianSortedArrays(v1,v2);
}