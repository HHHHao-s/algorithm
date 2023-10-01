#include "s.h"
/*
 * @lc app=leetcode.cn id=2136 lang=cpp
 *
 * [2136] 全部开花的最早一天
 */

// @lc code=start
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<int> id(plantTime.size());
        for(int i=0;i<id.size();i++){
            id[i]=i;
        }

        sort(id.begin(),id.end(), [&](int i, int j){return growTime[i]>growTime[j];});

        int cnt=0;
        int ans=0;
        for(int i=0;i<plantTime.size();i++){
            cnt+=plantTime[id[i]];
            ans=max(ans, cnt+growTime[id[i]]);
        }
        return ans;

    }
};
// @lc code=end

