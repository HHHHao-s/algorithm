#include "s.h"
/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:

    struct Data{
        
        int times;
        string s;
        
    };

    string decodeString(string s) {
        stack<Data> st;
        int i=0;
        int n =s.size();

        string ret;


        Data d = {0,""};
        st.push({0,""});
        while(i<n){
            
            char c = s[i];
            if(c<='z' && c>='a'){
                st.top().s += c;
            }else if(c>='0' && c<= '9'){
                d.times = d.times*10 + c-'0';
            }else if(c == '['){
                st.push(d);
                d = {0,""};
            }else if(c == ']'){
                string str;
                Data t = st.top();
                st.pop();
                str.reserve((t.times * t.s.size())+1);
                for(int i=0;i<t.times;i++){
                    str += t.s;
                }
                st.top().s+=str;
            }
            i++;
        }
        ret = st.top().s + d.s;
        return ret;
    }   
};
// @lc code=end

int main(){


    Solution s;

    cout << s.decodeString("222[bc]");

    return 0;
}