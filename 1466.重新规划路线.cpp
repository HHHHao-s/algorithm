#include "s.h"
/*
 * @lc app=leetcode.cn id=1466 lang=cpp
 *
 * [1466] 重新规划路线
 */

// @lc code=start
class Solution {
public:
    vector<vector<pair<int,int>>> m;
    
    unordered_set<int> visited;

    int minReorder(int n,const vector<vector<int>>& connections) {

        m = vector<vector<pair<int,int>>>(n);

        for(auto it: connections){
            m[it[0]].push_back({it[1],1});
            m[it[1]].push_back({it[0],0});
        }
    

        queue<int> q;

        q.push(0);
        

        int ans=0;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            visited.insert(x);

            for(auto it: m[x]){
                if(visited.count(it.first)==1){
                    continue;
                }

                ans +=  it.second;
                q.push(it.first);
            }


        }

        return ans;
       
       

    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.minReorder(5,{
        {1,0},
        {1,2},
        {3,2},
        {3,4},
    });


    return 0;
}