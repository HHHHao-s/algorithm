#include "s.h"
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:

    // int find_min(const vector<int> &nums)
    // {
    //     int left = 0, right = (int)nums.size() - 1;
    //     int ret = -1;
    //     while (left <= right)
    //     {
    //         int mid = (left + right) / 2;
    //         int x = nums[mid];
    //         int lx = nums[left];
    //         int rx = nums[right];
    //         if(x > lx && x > rx){ // defenitely in right side
    //             left = mid;

    //         }else if(x<lx&&x<rx){// defenitely in left side
    //             right = mid;

    //         }else if(lx < x && lx < rx){
    //             ret = left;
    //             break;
    //         }else if(x>lx && x< rx){
    //             ret = right+1;
    //             break;
    //         }
    //         else{
    //             if(left==right){
    //                 if(mid > 0 && mid<nums.size()-1 && nums[mid-1] > x && nums[mid+1]>x){
    //                     ret = mid;
    //                 }else if(mid<nums.size()-1 && nums[mid+1] < x){
    //                     ret = mid+1;
    //                 }else if(mid > 0 && nums[mid-1] < x){
    //                     ret = mid-1;
    //                 }
    //                 break;
    //             }else if(left == right-1){
    //                 if(nums[left] < nums[right]){
    //                     return left;
    //                 }else {
    //                     return right;
    //                 }
    //             }
    //         }
    //     }
    //     return ret;
    // }

    // int lowerBound(const vector<int> &nums, int target, int k)
    // {
    //     int left = 0, right = nums.size()-1, ans = (int)nums.size();
    //     while (left <= right)
    //     {
    //         int mid = (left + right) / 2;
    //         if (nums[(mid+k)%(nums.size())] >= target)
    //         {
    //             right = mid - 1;
    //             ans = mid;
    //         }
    //         else
    //         {
    //             left = mid + 1;
    //         }
    //     }
    //     return (ans+k)%(nums.size());
    // }

    // int search(const vector<int>& nums, int target) {

    //     int k=find_min(nums);
    //     int ans = lowerBound(nums,target,k);
    //     if(ans>=0 && ans < nums.size() && nums[ans] == target){
    //         return ans;
    //     }
    //     return -1;
    // }

    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }

};
// @lc code=end

int main(){




    return 0;
}