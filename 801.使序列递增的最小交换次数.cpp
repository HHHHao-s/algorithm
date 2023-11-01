#include "s.h"
/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] 使序列递增的最小交换次数
 */

// @lc code=start
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        
        int n = nums1.size();
        int a=0,b=1;

        for(int i=1;i<n;i++){
            int num1 = nums1[i];
            int num2 = nums2[i];
            int at = a,bt=b;
            a=n,b=n;
            if(num1>nums1[i-1] && num2>nums2[i-1]){
                a = min(a,at);
                b = min(b,bt+1);
            }if(num1 > nums2[i-1] && num2>nums1[i-1]){
                a = min(a,bt);
                b = min(b,at+1);

            }
        }
        return min(a,b);


    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums1 = {0,1,3,10,9,6},nums2={0,1,3,10,7,8};
    cout << s.minSwap(nums1,nums2);

}