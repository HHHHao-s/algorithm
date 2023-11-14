#include "s.h"
/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 *
 * [1334] 阈值距离内邻居最少的城市
 */

// @lc code=start
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int inf = 10000007;
        vector<vector<int>> grid(n ,vector<int>(n,inf));
        for(auto&edge:edges){

            grid[edge[0]][edge[1]] = edge[2];
            grid[edge[1]][edge[0]] = edge[2];
        }     
        for(int i=0;i<n;i++){
            grid[i][i] = 0;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][k]+grid[j][k]<grid[i][j]){
                        grid[i][j] = grid[i][k]+grid[j][k];
                    }
                }
            }
        }
        int mi_reachable=inf;
        int ans = n;
        for(int i=0;i<n;i++){
            int reachable=0;
            for(int j=0;j<n;j++){
                if(i!=j && grid[i][j]<=distanceThreshold){
                    reachable++;
                }
            }
            if(reachable<=mi_reachable){
                ans = i;
                mi_reachable = reachable;
            }
        }
        return ans;

    }
};
// @lc code=end

