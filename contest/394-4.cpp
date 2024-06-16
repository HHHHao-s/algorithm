#include "../s.h"

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        
        int m = edges.size();
        vector<vector<pair<int,int>>> grids(n);
        for(int i=0;i<m;i++){
            auto &edge = edges[i];
            grids[edge[0]].push_back({edge[1], edge[2]});
            grids[edge[1]].push_back({edge[0], edge[2]});
        }

        auto dij = [&](int begin, vector<vector<pair<int,int>>>& grid){
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
            vector<int> dis(n, INT_MAX/4);
            vector<int> vis(n);
            vis[begin] = 1;
            dis[begin] = 0;      
            for(auto [next, d]: grids[begin]){
                pq.push({d, next});
            }

            
            while(!pq.empty()){

                auto [d, node] = pq.top();
                pq.pop();
                if(vis[node]){
                    continue;
                }
                dis[node] = d;
                vis[node] =1;
                for(auto [next, d2]: grids[node]){
                    if(!vis[next]){
                        pq.push({d+d2, next});
                    }
                    
                }
            }
            return dis;
        };

        auto dis1 = dij(0, grids);
        auto dis2 = dij(n-1, grids);
        vector<bool> ans(m);
        for(int i=0;i<m;i++){
            int x = edges[i][0];
            int y = edges[i][1];
            int w = edges[i][2];
            if(dis1[x] + dis2[y]+w == dis1[n-1] || dis1[y]+dis2[x]+w==dis2[0]){
                ans[i] = true;
            }
        }
        return ans;
            

    


    }
};

int main(){
    Solution s;
    vector<vector<int>> edges={
        {2,0,1},{0,1,1},{0,3,4},{3,2,2}
    };
    printArr(s.findAnswer(4, edges));
}