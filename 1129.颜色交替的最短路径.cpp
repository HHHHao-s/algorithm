#include "s.h"
/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 *
 * [1129] 颜色交替的最短路径
 */

// @lc code=start
class Solution {
public:

    

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n);
        vector< vector < vector<int> > > next(2, vector < vector<int> >(n));
        for(auto i: redEdges){
            next[0][i[0]].push_back(i[1]);
        }
        for(auto i:blueEdges){
            next[1][i[0]].push_back(i[1]);
        }
        vector < vector<int> > dist(2, vector<int>(n, INT_MAX)); 

        queue<pair<int,int>> q;

        dist[0][0] = 0;
        dist[1][0] = 0;

        q.push({0,0});
        q.push({0,1});

        while(!q.empty()){

            auto p = q.front();
            int node = p.first, type=p.second;
            q.pop();
            int next_type = type^1;
            for(auto i: next[next_type][node]){

                if(dist[next_type][i]!=INT_MAX){
                    continue;
                }
                dist[next_type][i] = dist[type][node]+1;

                q.push({i, next_type});
            }

        }


        for(int i=0;i<n;i++){
            int smaller = min(dist[0][i], dist[1][i]);
            if(smaller==INT_MAX){
                ans[i]=-1;
            }else{
                ans[i] = smaller;
            }
        }

        return ans;
    }
};
// @lc code=end

int main(){

    Solution s;

    vector<vector<int>> redEdges={
        {0,1}
    };
    vector<vector<int>> blueEdges={
        {2,1}
    };

    printArr(s.shortestAlternatingPaths(3,redEdges,blueEdges));


    return 0;
}