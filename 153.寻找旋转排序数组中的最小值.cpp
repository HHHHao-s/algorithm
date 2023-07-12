#include "s.h"
/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution
{
public:
    int findMin(const vector<int> &nums)
    {
        if(nums.size()==1){
            return nums[0];
        }
        int left = 0, right = (int)nums.size() - 1;
        int ret = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int x = nums[mid];
            int lx = nums[left];
            int rx = nums[right];
            if(x > lx && x > rx){ // defenitely in right side
                left = mid;

            }else if(x<lx&&x<rx){// defenitely in left side
                right = mid;

            }else if(lx < x && lx < rx){
                ret = left;
                break;
            }else if(x>lx && x< rx){
                ret = right+1;
                break;
            }
            else{
                if(left==right){
                    if(mid > 0 && mid<nums.size()-1 && nums[mid-1] > x && nums[mid+1]>x){
                        ret = mid;
                        
                    }else if(mid<nums.size()-1 && nums[mid+1] < x){
                        ret = mid+1;
                    }else if(mid > 0 && nums[mid-1] < x){
                        ret = mid-1;
                    }
                    break;
                }else if(left == right-1){
                    if(nums[left] < nums[right]){
                        ret= left;
                    }else {
                        ret= right;
                    }
                    break;
                }
            }
        }
        return nums[ret];
    }
};
// @lc code=end
