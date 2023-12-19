#include "s.h"
/*
 * @lc app=leetcode.cn id=2065 lang=cpp
 *
 * [2065] 最大化一张图中的路径价值
 */

// @lc code=start
class Solution {
private:
    unordered_set<int> path,vis;
    vector<vector<pair<int,int>>> grid;
    int max_time;
    int ans{0};
    void backTrace(vector<int>& values, int node, int cur_time, int cur ){
        if(cur_time>max_time){
            return;
        }
        if(node==0){
            ans = max(ans, cur);
        }
        

        for(auto [next, time]: grid[node]){
            if(!path.count(next)){
                path.insert(next);
                backTrace(values, next, cur_time+time, cur+values[next]);
                path.erase(next);
            }else{
                backTrace(values, next, cur_time+time, cur);
            }
        }
        

    }

public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        ans = values[0];
        max_time = maxTime;
        grid.resize(values.size());
        for(auto &edge: edges){
            grid[edge[0]].push_back({edge[1],edge[2]});
            grid[edge[1]].push_back({edge[0],edge[2]});
        }
        path.insert(0);
        for(auto [next, time] : grid[0]){
            path.insert(next);
            backTrace(values, next, time, values[0]+values[next]);
            path.erase(next);

        }
        return ans;


    }
};
// @lc code=end

