#include "s.h"
/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
public:

    


    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> st;
        int n = rooms.size();
        vector<int> visited(n);

        st.push(0);

        while(!st.empty()){
            int x = st.front();
            st.pop();
            if(visited[x]){
                continue;
            }
            visited[x] = 1;
            for(int i: rooms[x]){
                st.push(i);
            }
        }

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                return 0;
            }
        }
        return 1;
    }
};
// @lc code=end

