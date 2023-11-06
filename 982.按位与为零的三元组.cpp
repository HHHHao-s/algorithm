#include "s.h"
/*
 * @lc app=leetcode.cn id=982 lang=cpp
 *
 * [982] 按位与为零的三元组
 */

// @lc code=start
class Solution {
public:
    int countTriplets(vector<int>& nums) {

        unordered_map<int,int> and_cnt;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(i==j){
                    and_cnt[nums[i]&nums[j]]++;
                }else{
                    and_cnt[nums[i]&nums[j]]+=2;
                }
            }
        }
        int ans =0;
        for(int i=0;i<nums.size();i++){
            for(auto [x,cnt]:and_cnt){
                if((nums[i]&x)==0){
                    ans += 3*cnt;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

