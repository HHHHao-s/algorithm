#include "s.h"
/*
 * @lc app=leetcode.cn id=2846 lang=cpp
 *
 * [2846] 边权重均等查询
 */

// @lc code=start
// https://oi-wiki.org/graph/lca/
// 求最近公共祖先
class Solution {
private:
    const int W = 27;

    int find(vector<int>&uf, int x){

        
        return uf[x]==x?x:uf[x]=find(uf, uf[x]);

    }

public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
        vector<vector<int>> count(n, vector<int>(W));

        vector<vector<pair<int,int>>> neighbour(n);

        for(auto & edge: edges){
            neighbour[edge[0]].push_back({edge[1],edge[2]});
            neighbour[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<vector<pair<int,int>>> queryArr(n);
        int m = queries.size();
        for(int i=0;i<m;i++){
            auto &query = queries[i];
            queryArr[query[0]].push_back({query[1], i});
            queryArr[query[1]].push_back({query[0], i});
        }

        vector<int> visited(n), lca(m), uf(n);

       

        function<void(int ,int)> dfs = [&](int node, int par){

            uf[node] = node;
            
            for(auto [next, ct]: neighbour[node]){
                if(next!=par){
                    count[next] = count[node];
                    count[next][ct]++;
                    dfs(next, node);
                    uf[next] = node;

                }
            }
            for(auto [node1, index]: queryArr[node]){

                if(node!=node1 && !visited[node1]){
                    continue;
                }
                lca[index] = find(uf, node1);
            }
            visited[node]=1;
            

        };
        dfs(0,-1);
        vector<int> res(m);
        for(int i=0;i<m;i++){
            int total = 0;
            int mx = 0;
            for(int j=1;j<=26;j++){
                int t = count[queries[i][0]][j]+count[queries[i][1]][j]-2*count[lca[i]][j];
                total+=t;
                mx = max(mx, t);
            }
            res[i] = total-mx;


        }

        return res;



    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> edges={
        {0,1,1},{1,2,1},{2,3,1},{3,4,2},{4,5,2},{5,6,2}
    };
    vector<vector<int>> que={
        {0,3},{3,6},{2,6},{0,6}
    };
    printArr(s.minOperationsQueries(7,edges, que));
}