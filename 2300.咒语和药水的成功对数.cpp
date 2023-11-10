#include "s.h"
/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */

// @lc code=start
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        
        vector<int> ret;
        for(int i=0;i<n;i++){
            int cnt = potions.end() - lower_bound(potions.begin(),potions.end(),(success+spells[i]-1)/spells[i]);
            ret.push_back(cnt);

        }
        return ret;
    }
};
// @lc code=end

