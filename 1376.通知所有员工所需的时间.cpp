#include "s.h"
/*
 * @lc app=leetcode.cn id=1376 lang=cpp
 *
 * [1376] 通知所有员工所需的时间
 */

// @lc code=start
class Solution {
public:

    


    int numOfMinutes(int n, int headID,const vector<int>& manager,const vector<int>& informTime) {
        vector<vector<pair<int,int>>> next(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
                next[manager[i]].push_back({i, informTime[manager[i]]});

        }

        queue<pair<int,int>> q;
        q.push({headID, 0});
        int ans=0;
        while(!q.empty()){
            auto [id, dist] = q.front();
            q.pop();
            
            for(auto it: next[id]){
                ans = max(ans, dist+it.second);
                q.push({it.first, dist+it.second});
            }
        }

        return ans;



    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.numOfMinutes(6,2,{4,2,-1,5,3,2},{0,0,1,2,10,0});


    return 0;
}