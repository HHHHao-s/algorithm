#include "s.h"
/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution {
private:
    vector<int> bc;

    int find(int x){
        return x==bc[x]?x:(bc[x]=find(bc[x]));
    }

    void merge(int x, int fa){
        int px = find(x);
        int py = find(fa);
        if (px != py) {
            bc[px] = py;
        }
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        bc.resize(n);

        

        

        vector<bool> vis(n);

        while(1){
            for(int i=0;i<n;i++){
                bc[i] = i;
            }
            queue<pair<int,int>> q;
            int a=0,b=0;

            int cnt=0;
            for(int i=0;i<n;i++){
                if(vis[i]){
                    cnt++;
                    continue;
                }
                vis[i] = 1;
                auto edge = graph[i];
                if(!edge.empty()){
                    a = i;
                    b = edge[0];
                    for(auto node:edge){
                        vis[node]=1;
                        merge(node, b);
                        q.push({node, b});
                    }
                    break;
                }
            }
            if(cnt==n){
                break;
            }

            while(!q.empty()){

                auto [node,par] = q.front();
                q.pop();

                for(auto adjacent: graph[node]){
                    if(!vis[adjacent]){
                        merge(adjacent, par==a?b:a);
                        q.push({adjacent,par==a?b:a});
                        vis[adjacent] = 1;
                    }else if(find(adjacent)==par){
                        return false;
                    }
                }

            }
        }

        return true;
        


    }
};
// @lc code=end

int main(){

    Solution s;

    vector<vector<int>> graph={
        {1,3},
        {0,2},
        {1,3},
        {0,2},
        {5,6,7},
        {4,6,7},
        {4,5,7},
        {4,5,6},
        

    };

    vector<vector<int>> graph2={
        {1,3},
        {0,2},
        {1,3},
        {0,2},
    };

    vector<vector<int>> graph3={
        {1},
        {0}

    };



    cout << s.isBipartite(graph2);


    return 0;
}