#include "s.h"
/*
 * @lc app=leetcode.cn id=2831 lang=cpp
 *
 * [2831] 找出最长等值子数组
 */

// @lc code=start
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        
        int ret =0;

        unordered_map<int,vector<int>> pos;

        for(int i=0;i<nums.size();i++){
            pos[nums[i]].push_back(i);
        }

        for(auto &[_, vec] : pos){

            for(int l=0,r=0;r<vec.size();r++){

                while((vec[r]-vec[l]-(r-l)>k)){
                    l++;
                }

                ret = max(r-l+1, ret);

            }

        }

        return ret;

    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int> nums = {3,1,5,3,1,1};
    cout << s.longestEqualSubarray(nums, 2);

}