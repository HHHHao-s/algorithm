#include "s.h"
/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * [802] 找到最终的安全状态
 */

// @lc code=start
// class Solution {
// public:

//     set<int> ans;
//     vector<int> visited;
//     vector<int> travel;

//     int dfs(vector<vector<int>>& graph, int x){

        
//         if(graph[x].size()==0){ // terminate
//             visited[x]=1;
//             ans.insert(x);
//             return 1;
//         }else{
//             if(travel[x]){
//                 return 0;
//             }
//             if(visited[x]){
//                 if(ans.count(x)){
//                     return 1;
//                 }else{
//                     return 0;
//                 }               
//             }
            
                
//             visited[x] = 1;
//             travel[x] = 1;
//             int i=0;
//             for(;i<graph[x].size();i++){
//                 int is_terminate = dfs(graph, graph[x][i]);
//                 if(!is_terminate){
//                     break;
//                 }
//             }
//             travel[x]=0;
//             if(i==graph[x].size()){
//                 ans.insert(x);
//                 return 1;
//             }

//         }
//         return 0;

//     }


//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         visited = vector<int>(n,0);
//         travel = vector<int>(n,0);
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                 dfs(graph, i);
//             }
            
//         }
//         vector<int> ret;
//         for(auto i: ans){
//             ret.push_back(i);
//         }
//         return ret;
//     }   
// };

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> color(n);

        function<bool(int)> safe = [&](int x) {
            if (color[x] > 0) {
                return color[x] == 2;
            }
            color[x] = 1;
            for (int y : graph[x]) {
                if (!safe(y)) {
                    return false;
                }
            }
            color[x] = 2;
            return true;
        };

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (safe(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};


// @lc code=end

int main(){

    Solution s;

    vector<vector<int>> graph={
        {},
        {0,2,3,4},
        {3},
        {4},
        {}
    };

    printArr(s.eventualSafeNodes(graph));



    return 0;
}