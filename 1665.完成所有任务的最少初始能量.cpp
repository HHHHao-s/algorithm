#include "s.h"
/*
 * @lc app=leetcode.cn id=1665 lang=cpp
 *
 * [1665] 完成所有任务的最少初始能量
 */

// @lc code=start
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<tuple<int,int,int>> ps;
        
        for(auto &task: tasks){
            ps.push_back({task[1]-task[0],task[0], task[1]});

        }
        sort(ps.begin(), ps.end());
        int result = 0;
        for(auto [diff, a,b]: ps){
            result = max(result+a, b);
        }
        return result;
        

    }
};
// @lc code=end

