#include "s.h"
/*
 * @lc app=leetcode.cn id=1306 lang=cpp
 *
 * [1306] 跳跃游戏 III
 */

// @lc code=start
class Solution {
public:
    bool canReach(const vector<int>& arr, int start) {
        
        int step=0;
        int n = arr.size();
        vector<int> vis(n);
        queue<int> q;

        q.push(start);
        

        while(!q.empty()){
                        
            int index = q.front();
            q.pop();

            int bias = arr[index];

            if(vis[index]==1){
                continue;
            }
            vis[index]=1;

            if(bias==0){
                return 1;
            }

            if(index>=bias){
                q.push(index-bias);
            }
            if(index+bias<n){
                q.push(index+bias);
            }
                        
        }
        return 0;
    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.canReach(
        {4,2,3,0,3,1,2},
        0
    );

    return 0;
}
