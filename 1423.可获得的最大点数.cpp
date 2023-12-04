#include "s.h"
/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
        int cur = 0;
        for(int i=0;i<k;i++){
            cur+=cardPoints[i];
        }
        ans = cur;
        for(int l=k;l-->0;){
            cur-=cardPoints[l];
            cur+=cardPoints[cardPoints.size()-(k-l)];
            ans = max(ans ,cur);
        }
        return ans;
    }
};
// @lc code=end

