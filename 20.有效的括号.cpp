#include "s.h"
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution{
public:
    bool isValid(string s){

        int n=s.size();

        stack<char> st;

        for(int p=0;p<n;p++){
            char c = s[p];
            if(c=='(' || c=='[' || c=='{'){
                st.push(c);

            }
            else{
                if(st.size()==0) return false;
                switch (c)
                {
                case ')':
                    if(st.top() == '(') st.pop();
                    else return false;
                    break;
                case ']':
                    if(st.top() == '[') st.pop();
                    else return false;
                    break;
                case '}':
                    if(st.top() == '{') st.pop();
                    else return false;
                    break;
                default:
                    break;
                }
            }

            
        }
        return st.size()==0;
        
    }
    
};
// @lc code=end

