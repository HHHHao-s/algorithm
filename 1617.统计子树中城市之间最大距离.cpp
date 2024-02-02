#include "s.h"
/*
 * @lc app=leetcode.cn id=1617 lang=cpp
 *
 * [1617] 统计子树中城市之间最大距离
 */

// @lc code=start
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {

        vector<vector<int>> grid(n);
        for(auto &edge: edges){
            grid[edge[0]-1].push_back(edge[1]-1);
            grid[edge[1]-1].push_back(edge[0]-1);
        }

        function<int(int ,int ,int)> dfs=[&](int node, int far, int mask){
            int ret=0;
            for(int next: grid[node]){
                if(mask & (1<<next) && far!=next){
                    int a = 1 + dfs(next, node, mask);
                    ret = max(a, ret);
                }
            }
            return ret;

        };
        vector<int> ans(n-1);
        for(int i=1;i<(1<<n);i++){
            int mask = i;
            queue<int> q;
            int root=-1;
            for(int j=0;j<n;j++){
                if(mask & (1<<j)){
                    //check
                    q.push(j);
                    mask ^= (1<<j);
                    root = j;
                    break;
                }
            }
            int far=-1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int next: grid[node]){
                    if(mask & (1<<next)){
                        q.push(next);
                        mask^=(1<<next);
                    }
                }
                far = node;
            }
            if(mask!=0){
                continue;
            }
            
            int d = dfs(far,-1, i);
            if(d>0){
                ans[d-1]++;
            }
            
        }

        return ans;
    }
};
// @lc code=end

