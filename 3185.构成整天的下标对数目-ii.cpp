#include "s.h"
/*
 * @lc app=leetcode.cn id=3185 lang=cpp
 *
 * [3185] 构成整天的下标对数目 II
 */

// @lc code=start
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<long long> cnt(24);
        cnt[hours[0]%24]++;
        long long ans = 0;
        for(int i=1;i<hours.size();i++){
            int counter = 24 - hours[i]%24;
            ans += cnt[counter];
            cnt[hours[i]%24]++;
        }
        return ans;
    }
};
// @lc code=end

