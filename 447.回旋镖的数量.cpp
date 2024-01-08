#include "s.h"
/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int ans = 0;
        for(auto &point:points){
            unordered_map<int, int> cnt;
            for(auto &p2:points){
                int dis = (point[0]-p2[0])*(point[0]-p2[0])+(point[1]-p2[1])*(point[1]-p2[1]);
                cnt[dis]++;

            }

            for(auto [dis, ct]: cnt){
                ans += ct*(ct-1);
            }

        }

        return ans;
    }
};
// @lc code=end

