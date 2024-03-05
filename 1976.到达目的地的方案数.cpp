#include "s.h"
/*
 * @lc app=leetcode.cn id=1976 lang=cpp
 *
 * [1976] 到达目的地的方案数
 */

// @lc code=start
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<long long>> grid(n, vector<long long>(n, LONG_LONG_MAX));
        for(auto &r: roads){
            grid[r[0]][r[1]] = r[2];
            grid[r[1]][r[0]] = r[2];
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> dis(n, LONG_LONG_MAX), cnt(n);

        dis[0] = 0;
        cnt[0] = 1;
        pq.push({0,0});
        const long long MOD = 1e9+7;

        while(!pq.empty()){
            auto [d, cur] = pq.top();
            pq.pop();
            if(d>dis[cur]){
                continue;
            }
            for(int i=0;i<n;i++){
                if(grid[cur][i]!=LONG_LONG_MAX){
                    if(dis[i]==dis[cur]+grid[cur][i]){
                        cnt[i] = (cnt[i]+cnt[cur])%MOD;
                    }else if(dis[i]> dis[cur]+grid[cur][i]){
                        dis[i] =  dis[cur]+grid[cur][i];
                        cnt[i] =cnt[cur];
                        pq.push({dis[i], i});
                        
                    }
                    
                    
                }
            }
        }
        return cnt[n-1];
    }
};
// @lc code=end

