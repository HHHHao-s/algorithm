#include "s.h"
/*
 * @lc app=leetcode.cn id=2708 lang=cpp
 *
 * [2708] 一个小组的最大实力值
 */

// @lc code=start
class Solution {
public:
    
    

    long long maxStrength(vector<int>& nums) {
        
        int n = nums.size();
        vector<pair<long long,long long>> memo(1<<n, {LONG_LONG_MAX,LONG_LONG_MIN});

        auto dfs = [&](auto &&dfs, int x) -> pair<long long,long long>{

            if(x==0){
                return {1ll,1ll};
            }
            if(memo[x].first!=LONG_LONG_MAX){
                return memo[x];
            }
            long long mx = LONG_LONG_MIN;
            long long mn = LONG_LONG_MAX;
            for(int i=0;i<n;i++){
                if(x & (1<<i)){

                    auto [dmx, dmn] = dfs(dfs, x^(1<<i));
                    mx = max({mx, nums[i]*dmx, nums[i]*dmn,(long long) nums[i]});
                    mn = min({mn, nums[i]*dmx, nums[i]*dmn,(long long) nums[i]});       
                                 

                }
            }
            memo[x] = {mx,mn};
            return {mx, mn};

        };

        return  dfs(dfs, (1<<n) -1).first;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums={3,-1,-5,2,5,-9};
    cout << s.maxStrength(nums);
}