#include "s.h"
/*
 * @lc app=leetcode.cn id=2050 lang=cpp
 *
 * [2050] 并行课程 III
 */

// @lc code=start
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> grid(n);

        vector<int> inDegree(n);

        for(const auto &relation: relations){
            grid[relation[0]-1].push_back(relation[1]-1);
            inDegree[relation[1]-1]++;
        }

        vector<int> last_time(n);

        deque<int> q;

        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                last_time[i] = time[i];
                q.push_back(i);
            }
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop_front();
            for(auto next:grid[node]){
                inDegree[next]--;
                last_time[next] = max(last_time[next], time[next]+last_time[node]);
                if(inDegree[next]==0){
                    q.push_back(next);
                }
            }

        }
        return *max_element(last_time.begin(), last_time.end());
        

    }
};
// @lc code=end

