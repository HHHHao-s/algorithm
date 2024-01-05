#include "s.h"
/*
 * @lc app=leetcode.cn id=1944 lang=cpp
 *
 * [1944] 队列中可以看到的人数
 */

// @lc code=start
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {

        deque<int> st;
        vector<int> ret(heights.size());
        for(int i=heights.size();i-->0;){
            int height = heights[i];
            int cnt = 0;

            while(!st.empty() && height>st.front()){
                
                cnt++;
                
                st.pop_front();

            }
            if(!st.empty()){
                cnt+=1;
            }
            st.push_front(height);
            
            ret[i] = cnt;
        }
        return ret;

    }
};
// @lc code=end

