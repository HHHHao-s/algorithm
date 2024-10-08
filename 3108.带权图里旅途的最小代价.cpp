#include "s.h"
/*
 * @lc app=leetcode.cn id=3108 lang=cpp
 *
 * [3108] 带权图里旅途的最小代价
 */

// @lc code=start
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        

        vector<int> ans;

        unordered_map<int,int> fa, calc;
        
        vector<vector<pair<int,int>>> grid(n);
        for(auto &edge: edges){

            int u=edge[0],v=edge[1],w=edge[2];
            grid[u].push_back({v,w});
            grid[v].push_back({u,w});

        }

        for(int i=0;i<n;i++){
            if(fa.count(i)==0){
                fa[i] = i;
                calc[i] = (1<<30)-1;
                queue<int>q;    
                q.push(i);
                while (!q.empty())
                {
                    int cur  = q.front();
                    q.pop();
                    for(auto [next, w]: grid[cur]){

                        if(!fa.count(next)){
                            fa[next] = i;
                            
                            q.push(next);
                        }
                        calc[i] &= w;

                    }


                }
            
            }

        }

        for(auto &q :query){

            int start = q[0], end= q[1];
            if(fa[start]==fa[end]){
                ans.push_back(calc[fa[start]]);
            }else{
                ans.push_back(-1);
            }

        }
        return ans;


    }
};
// @lc code=end

