#include "s.h"
/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.

*/

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        

        vector<vector<int>> grid(2010);
        unordered_map<int, int> im;

        for(auto e: employees){
            im[e->id] = e->importance;
            for(auto next: e->subordinates){
                grid[e->id].push_back(next);
                
            }

        }
       

        auto dfs = [&](auto &&dfs, int cur) ->int{

            int ret = im[cur];
            for(auto next: grid[cur]){
                ret += dfs(dfs, next);
            }
            return ret;


        };

        return dfs(dfs ,id);


    }
};
// @lc code=end

