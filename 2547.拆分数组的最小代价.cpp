#include "s.h"
/*
 * @lc app=leetcode.cn id=2547 lang=cpp
 *
 * [2547] 拆分数组的最小代价
 */

// @lc code=start
class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        unordered_map<int,long long> dp;
    

        std::function<long long(int)> f = [&](int r){
            if(r<0){
                return 0ll;
            }
            if(dp.count(r)){
                return dp[r];
            }
            long long now = numeric_limits<int>::max();
            int single = 0;
            unordered_map<int, int> cnt;
            for(int l =r ;l>=0; l--){
                cnt[nums[l]]++;
                if(cnt[nums[l]]==1){
                    single++;
                }else if(cnt[nums[l]]==2){
                    single--;
                }
                now = min(now, k+f(l-1)+r-l+1-single);

            }
            dp[r] = now;
            return now;
        };
        int ret = f(nums.size()-1);
        return ret;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums ={1,2,1,2,1,3,3};
    cout <<s.minCost(nums, 2);
}