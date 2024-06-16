#include "../s.h"

class Solution {

private:
    vector<vector<int>> g;
    unordered_map<int ,vector<int>> memo;
    int dfs(int cur, int times, int par, vector<int>& coins, int k){
        if(memo.count(cur) && memo[cur][times]!=-1){
            return memo[cur][times];
        }
        int res1 = (coins[cur]>>times)-k;
        int res2 = coins[cur]>>(times+1);
        for(auto next: g[cur]){
            if(next!=par){
                res1 += dfs(next, times,cur, coins, k);
                if(times+1<14)
                    res2 += dfs(next, times+1, cur, coins, k);
            }
        }
        if(memo.count(cur)==0)
            memo[cur] = vector<int>(14,-1);
        memo[cur][times] = max(res1,res2);
        return max(res1,res2);

    }

public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        g=vector<vector<int>>(n);

        for(const auto&edge: edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        return dfs(0,0,-1,coins,k);

    }
};