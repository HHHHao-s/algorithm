#include "s.h"
/*
 * @lc app=leetcode.cn id=847 lang=cpp
 *
 * [847] 访问所有节点的最短路径
 */

// @lc code=start
class Solution {
private:
    int ans{INT_MAX};
    vector<vector<int>> grid;
    

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        grid.resize(graph.size());
        for(int i=0;i<graph.size();i++){
            for(int j: graph[i]){
                grid[i].push_back(j);
                grid[j].push_back(i);
            }
            
        }
        struct Status{
            int node;
            bitset<12> mask;
            int dist;
        };

        queue<Status> q;
        unordered_map<int ,unordered_set<bitset<12>>> vis;
        bitset<12> msk;
        for(int j=graph.size();j<12;j++){
            msk.set(j);
        }
        for(int i=0;i<graph.size();i++){
           
            
            msk.set(i);
            q.push({i, msk, 0});
            vis[i].insert(msk);
            msk.reset(i);
        }
         while(!q.empty()){
            auto [node, mask, dist] = q.front();
            q.pop();
            if(mask.all()){
                return dist;
            }
            for(int nx: grid[node]){
                bool have = mask.test(nx);
                mask.set(nx);
                if(!vis[nx].count(mask)){
                    q.push({nx, mask, dist+1});
                    vis[nx].insert(mask);
                }
                mask[nx] = have;
                
            }
        }
        return 0;


    }
};
// @lc code=end

