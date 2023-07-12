#include "s.h"
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    int mySearch(const vector<int>& nums, int target, int left, int right){// 搜索位置
        int ret = -1;
        if(left<0 || right>nums.size()){
            return -1;
        }

        while(left<=right){
            int mid = (right + left)/2;
            int val = nums[mid];
            if(val == target){
                ret = mid;
                break;
            }else if(val> target){
                right = mid -1;
            }else{
                left = mid + 1;
            }
        }
        return ret;
    }

    // int lowerBound(const vector<int> &nums, int target)
    // {
    //     int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
    //     while (left <= right)
    //     {
    //         int mid = (left + right) / 2;
    //         if (nums[mid] >= target)
    //         {
    //             right = mid - 1;
    //             ans = mid;
    //         }
    //         else
    //         {
    //             left = mid + 1;
    //         }
    //     }
    //     return ans;
    // }

    // int upperBound(const vector<int> &nums, int target)
    // {
    //     int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
    //     while (left <= right)
    //     {
    //         int mid = (left + right) / 2;
    //         if (nums[mid] > target)
    //         {
    //             right = mid - 1;
    //             ans = mid;
    //         }
    //         else
    //         {
    //             left = mid + 1;
    //         }
    //     }
    //     return ans;
    // }

    // vector<int> searchRange(const vector<int> &nums, int target)
    // {
    //     int leftIdx = lowerBound(nums, target);
    //     int rightIdx = upperBound(nums, target) - 1;
    //     if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target)
    //     {
    //         return vector<int>{leftIdx, rightIdx};
    //     }
    //     return vector<int>{-1, -1};
    // }

    vector<int> searchRange(const vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1,-1};
        }
        int left_bound=-1,right_bound=-1;
        int n = nums.size()-1;

        int mid = mySearch(nums,target,0,n);
        int left_cur = mid;
        while(left_cur!=-1){
            left_bound = left_cur;
            left_cur = mySearch(nums,target, 0, left_cur-1);

        }
        int right_cur = mid;
        while(right_cur!=-1){
            right_bound = right_cur;
            right_cur = mySearch(nums,target,right_cur+1, n);
        }

        return {left_bound, right_bound};

    }
};
// @lc code=end

int main()
{

    Solution s;
    vector<int> ans = s.searchRange({0, 1, 2, 4, 4, 4, 4, 8}, 4);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}