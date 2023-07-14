#include "s.h"
/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        if(n==1){
            return {0};
        }
        vector<int> ret(n);

        
        stack<int> st;

        for(int i=0;i<n;i++){
            char x = temperatures[i];
            
            while(!st.empty() && x>temperatures[st.top()]){
                ret[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        // while(!st.empty()){
        //     ret[st.top()] = 0;
        //     st.pop();
            
        // }
        return ret;
    }

};
// @lc code=end

