#include "s.h"
/*
 * @lc app=leetcode.cn id=995 lang=cpp
 *
 * [995] K 连续位的最小翻转次数
 */

// @lc code=start
class Solution {
public:
    int minKBitFlips(const vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n+1);
        int cur=0;
        int ans = 0;
        for(int i=0;i<n;i++){
            cur ^= diff[i];
            if(cur==nums[i]){
                if(i+k>n){
                    return -1;
                }
                cur ^= 1;
                diff[i+k] ^= 1;
                ans++;
            }
        }
        return ans;

    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.minKBitFlips({0,0,0,0,1,0,1,1,1,0}, 4);

}