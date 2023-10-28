#include "s.h"
/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 *
 * [1124] 表现良好的最长时间段
 */

// @lc code=start
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        
        vector<int> s(n+1);
        //选择前缀和s[r] > s[l]，且最大的r-l
        stack<int> st;
        st.push(0);
        int cur = 0;
        for(int i=1;i<=n;i++){
            s[i] = s[i-1]+(hours[i - 1] > 8 ? 1 : -1);
            // 递减的stack
            if(s[i]<s[st.top()]) st.push(i);
        }
        int ans = 0;
        for(int i=n;i>0;i--){
            while(!st.empty() && s[i]>s[st.top()]){
                ans = max(ans, i-st.top());
                st.pop();
            }
        }
        return ans;
    }
};
// @lc code=end

