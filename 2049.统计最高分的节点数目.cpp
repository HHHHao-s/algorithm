#include "s.h"
/*
 * @lc app=leetcode.cn id=2049 lang=cpp
 *
 * [2049] 统计最高分的节点数目
 */

// @lc code=start
class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> grid(n);
        for(int i=1;i<n;i++){
            grid[i].push_back(parents[i]);
            grid[parents[i]].push_back(i);

        }

        vector<long long> sz(n);

        function<int(int ,int)> dfs1 = [&](int node ,int far){
            int ret = 1;
            for(int i=0;i<grid[node].size();i++){
                if(far != grid[node][i]){
                    ret += dfs1(grid[node][i], node);
                }
            }
            sz[node] = ret;
            return ret;

        };
        dfs1(0, -1);
        long long ans = -1;
        int ret = 0;
        function<void(int ,int ,int)> dfs2 = [&](int node, int far, long long fs){
            

            long long cur_ans = fs;
            for(int i =0;i<grid[node].size();i++){
                if(grid[node][i]!=far){
                    cur_ans *= sz[grid[node][i]];
                    dfs2(grid[node][i], node,n- sz[grid[node][i]]);
                }
            }
            if(cur_ans == ans){
                ret++;
            }else if( cur_ans > ans){
                ret = 1;
                ans = cur_ans;
            }
        };

        dfs2(0 ,-1, 1);
        return ret;
    }
};
// @lc code=end

