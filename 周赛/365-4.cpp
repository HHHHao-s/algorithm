#include "s.h"

class Solution {
private:
    vector<pair<int,int>> union_find;
    unordered_set<int> visited;

    pair<int,int> find(int x){
        return x==union_find[x].first?union_find[x]:union_find[x]=find(union_find[x].first);
    }

    void merge(int x, int y){
        auto [fx,tx] = find(x);
        auto [fy,tx] = find(y);
        if(fx!=fy){
            union_find[fx].first = fy;
            union_find[fy].second += union_find[fx].second;
        }
    }


    int dfs(int node, vector<int>& edges){
        if(visited.count(node)){
            auto [fx, tx] = find(node);
            return tx;
        }

        visited.insert(node);
        if(visited.count(edges[node])){
            merge(node, edges[node]);
        }else{
            int tx = dfs(edges[node], edges);
        }
        
        
        
    }

public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        union_find.resize(n);
        for(int i=0;i<n;i++){
            union_find[i] = {i,1};
        }

        for(int i=0;i<n;i++){
            dfs(i,edges);
        }
    }
};

int main(){




    return 0;
}