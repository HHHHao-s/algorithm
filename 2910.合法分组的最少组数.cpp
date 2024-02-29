#include "s.h"
/*
 * @lc app=leetcode.cn id=2910 lang=cpp
 *
 * [2910] 合法分组的最少组数
 */

// @lc code=start
class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        
        unordered_map<int,int> cnt;
        for(int num: nums){
            cnt[num]++;
        }
        int mn = INT_MAX;
        for(auto [_, ct]: cnt){
            mn = min(ct, mn);
        }
        int ans = INT_MAX;
        for(int i=mn;i>=1;i--){
            int can =1;
            int tmp_ans = 0;
            for(auto [_ , ct] : cnt){
                if((ct/(i+1) + ct%(i+1) >= i) ||(ct%(i+1)==0)){
                    tmp_ans += ct/(i+1)+((ct%(i+1))>0);

                }else{
                    can = 0;
                    break;
                }
            }
            if(can){
                ans = min(ans, tmp_ans);

            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums = {3,2,3,2,3};
    cout<<s.minGroupsForValidAssignment(nums);
}