#include "../s.h"

class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = edges.size()+1;
        vector<vector<int>> grid(n);
        for(int i=0;i<n-1;i++){   
            grid[edges[i][0]].push_back(edges[i][1]);
            grid[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<long long>> memo(2, vector<long long>(n,-1));

        function<long long(int, int,int)> dfs=[&](int fa, int have, int cur)->long long{
            
            if(memo[have][cur]!=-1){
                return memo[have][cur];
            }
            long long cnt1=values[cur]; // use it
            long long cnt2=0; // not use it
            if(have==0){
                if(grid[cur].size()==1 && grid[cur][0]==fa){
                    // leave
                    return 0;
                }
                for(auto next: grid[cur]){
                    if(next==fa){
                        continue;
                    }
                    cnt1 += dfs(cur, 0, next);
                    cnt2 += dfs(cur, 1, next);
                }
            }else{
                if(grid[cur].size()==1 && grid[cur][0]==fa){
                    // leave
                    return values[cur];                  
                }
                for(auto next: grid[cur]){
                    if(next==fa){
                        continue;
                    }
                    cnt1 += dfs(cur, 1, next);

                }
            }
            long long ret = max(cnt1, cnt2);
            memo[have][cur]=ret;
            return ret;

        };

        return dfs(-1,0,0);


    }
};