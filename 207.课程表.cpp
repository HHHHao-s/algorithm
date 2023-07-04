#include "s.h"
/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
// class Solution {
// public:



//     bool canFinish(int n,const vector<vector<int>>& p) {
//         if(n==1){ return 1;}
//         unordered_map<int,int> in_degree_{};
//         unordered_set<int> zero_degree_{};
//         vector<vector<int>> node_map_{};
//         for(int i=0;i<n;i++){
//             zero_degree_.insert(i);
//         }

//         for(int i=0;i<p.size();i++){
//             in_degree_[p[i][1]]++;
//             node_map_[p[i][0]].push_back(p[i][1]);
//             zero_degree_.erase(p[i][1]);
//         }
        
//         while(!zero_degree_.empty()){
//             int x = *zero_degree_.begin();
//             zero_degree_.erase(zero_degree_.begin());
//             int n = node_map_[x].size();
//             for(int i=0;i<n;i++){
//                 int that = node_map_[x][i];
//                 in_degree_[that]--;
//                 if(in_degree_[that]==0){
//                     zero_degree_.insert(that);
//                     in_degree_.erase(that);
//                 }
                
//             }
//         }
//         return in_degree_.empty();
//     }   
// };
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indeg;

public:
    bool canFinish(int numCourses,const vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int u = q.front();
            q.pop();
            for (int v: edges[u]) {
                --indeg[v];
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return visited == numCourses;
    }
};

// @lc code=end

int main(){

    Solution s;
    cout << s.canFinish(4,{{1,0},{1,2},{3,1}});

    return 0;
}
