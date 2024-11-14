#include "s.h"
class Solution {

public:

    int ans =0;

    vector<vector<int>> grid;

    int dfs(int node, int fa){
        int sum=0, first=-1, can =1;
        for(int next: grid[node]){
            if(next!=fa){
                int ct = dfs(next, node);
                sum+=ct;
                if(first==-1){
                    first = ct;
                }else{
                    if(first!=ct){
                        can =0 ;
                    }
                }
            }
        }

        if(can){
            ans ++;
        }
        return sum + 1;


    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        grid.assign(n, {});
        for(auto &edge: edges){
            grid[edge[0]].push_back(edge[1]);
            grid[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1);
        return ans;

    }
};