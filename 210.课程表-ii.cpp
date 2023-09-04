#include "s.h"
/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n = prerequisites.size();

        vector<int> in(numCourses), out(numCourses);

        vector<vector<int>> edges(numCourses);

        for(int i=0;i<n;i++){
            int a = prerequisites[i][0];
            int pre = prerequisites[i][1];

            edges[pre].push_back(a);

            in[a]++;
            out[pre]++;

        }
        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(in[i]==0){
                q.push(i);
            }
        }

        vector<int> ret;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ret.push_back(node);
            for(auto edge: edges[node]){
                
                in[edge]--;
                if(in[edge]==0){
                    q.push(edge);
                }
                
            }
            
        }

        if(ret.size()==numCourses){
            return ret;
        }else{
            return {};
        }


    }
};
// @lc code=end

int main(){

    Solution s;
    
    vector<vector<int>> prerequisites={
        {1,0},{1,2},{0,1}
    };

    printArr( s.findOrder(3, prerequisites));

    return 0;
}