#include "s.h"
/*
 * @lc app=leetcode.cn id=815 lang=cpp
 *
 * [815] 公交路线
 */

// @lc code=start
class Solution {
public:
    int numBusesToDestination(const vector<vector<int>>& routes, int source, int target) {
        
        int n = routes.size();

        unordered_map<int, vector<int>> station2routes;

        if(target==source){
            return 0;
        }



        for(int i=0;i<n;i++){
            for(auto x: routes[i]){
                station2routes[x].push_back(i);
                
                
            }
        }
        
        int step=1;
        queue<int> q;
        unordered_set<int> vis;
        for(auto &source_route : station2routes[source]){
            q.push(source_route);
            
        }
        
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int route = q.front();
                q.pop();
                
                if(!vis.count(route)){
                    vis.insert(route);
                    for(auto station: routes[route]){
                        if(station == target){
                            return step;
                        }
                        for(auto &next_route: station2routes[station]){
                            if(!vis.count(next_route)){
                                q.push(next_route);
                            }
                            
                        }
                    }
                }
            }
            
            step++;

        }
        return -1;

    }
};
// @lc code=end

int main(){
    Solution s;

    cout << s.numBusesToDestination({
        {7,12},
        {4,5,15,13},
        {6},
        {9,7},
        {9,13}
    }, 15, 12);


    
}