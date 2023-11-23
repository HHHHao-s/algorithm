#include "s.h"
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
private:
    struct Status{
        int l, r, whole, mx;
    };

    Status divide(const vector<int>& nums, int l ,int r, int n){

        if(l==r){
            return {nums[l], nums[r], nums[l], nums[l]};
        }

        int mid = (l+r)/2;

        Status s1 = divide(nums, l, mid, n);
        Status s2 = divide(nums, mid+1, r, n);
        int whole = s1.whole + s2.whole;
        
        int mxl = max({s1.l, s2.l+s1.whole, whole ,s1.whole});
        int mxr = max({s2.r, s1.r+s2.whole, whole, s2.whole});
        int cross = max({s2.l+s1.whole, s1.r+s2.whole, whole, s1.r+s2.l});
        int mx = max({s1.mx ,s2.mx, cross});
        return {mxl, mxr, whole, mx};


    }

public:
    int maxSubArray(const vector<int>& nums) {

        int n = nums.size();
        Status s = divide(nums, 0, n-1, n);
        return s.mx;

    }
};
// @lc code=end


int main(){

    Solution s;

    cout << s.maxSubArray({-2,1,-3,4,-1,2,1,-5,4});

    return 0;
}