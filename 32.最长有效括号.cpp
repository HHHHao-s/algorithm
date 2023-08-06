#include "s.h"
/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int ans= 0;
        st.push(-1);
        for(int i=0;i<n;i++){
            char c = s[i];
            if(c == '('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    ans = max(i-st.top(), ans);
                }

            }
        }
        return ans;
    }
};
// @lc code=end

