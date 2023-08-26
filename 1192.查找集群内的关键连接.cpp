#include "s.h"
/*
 * @lc app=leetcode.cn id=1192 lang=cpp
 *
 * [1192] 查找集群内的关键连接
 */

// @lc code=start
class Solution {
public:

    vector<int> low, dfn, vis;
    vector<vector<int>> ans;
    vector<vector<int>> adj;
    int now;

    int n;

    void tarjan(int cur, int fa){// 找环

        now++;
        vis[cur] = 1;

        low[cur]=dfn[cur]=now;

        for(auto it: adj[cur]){
            if(it==fa){
                continue;
            }

            if(!vis[it]){
                tarjan(it, cur);
                low[cur] = min(low[it], low[cur]);// 逆回来，设置自己的low为子树的low
                if(dfn[cur] < low[it]){ // 如果子树没有碰到自己或之前的节点，那么这个路径肯定是关键路径
                    ans.push_back({cur,it});
                }
            }else{
                low[cur] = min(low[cur], dfn[it]); // 顺向碰到之前访问过的，时间更小的地方，修改自己的low
            }

        }

    }

    vector<vector<int>> criticalConnections(int _n,const vector<vector<int>>& connections) {
        n = _n;
        adj.resize(n);
        for(auto i: connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        low.resize(n);
        dfn.resize(n);
        vis.resize(n);
        now = 0;

        tarjan(0,-1);

        return ans;

    }
};
// @lc code=end

int main(){

    Solution s;
    print2d(s.criticalConnections(4,{
        {0,1},
        {1,2},
        {2,0},
        {1,3}
    }));

    return 0;
}