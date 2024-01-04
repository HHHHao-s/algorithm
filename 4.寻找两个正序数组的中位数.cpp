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
        if(n1>n2){
            return findMedianSortedArrays(nums2, nums1);
        }

        int left = 0, right = n1;
        int need = (n1+n2)/2;
        while(left<=right){
            int mid1 = (right+left)/2;
            int mid2 = need-mid1;

            int a = mid1-1>=0 ?nums1[mid1-1]: INT_MIN;
            int b = mid1<n1?nums1[mid1]:INT_MAX;
            int c = mid2-1>=0 ? nums2[mid2-1]:INT_MIN;
            int d = mid2<n2 ? nums2[mid2]: INT_MAX;

            if(a<=d && c<=b){
                if((n1+n2)%2==0){
                    return ((double)max(a,c)+(double)min(b,d))/2;
                }else{
                    return (double)min(b,d);
                }
                
            }else if(a>d){
                right=mid1-1;

            }else if(c>b){
                left = mid1+1;
            }

        }

        return -1;

        

        
    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int>v1 = {1,2};
    vector<int>v2 = {3,4};
    cout << s.findMedianSortedArrays(v1,v2);
}