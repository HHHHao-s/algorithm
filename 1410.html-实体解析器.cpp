#include "s.h"
/*
 * @lc app=leetcode.cn id=1410 lang=cpp
 *
 * [1410] HTML 实体解析器
 */

// @lc code=start
class Solution {
public:
    string entityParser(string text) {
        string ans;
        for(int i =0;i<text.size();i++){
            if(text[i]=='&'){
                if(strncmp(&text[i], "&quot;", 6)==0){
                    ans.push_back('\"');
                    i+=5;
                }else if(strncmp(&text[i], "&apos;",6)==0){
                    ans.push_back('\'');
                    i+=5;
                }else if(strncmp(&text[i], "&amp;",5)==0){
                    ans.push_back('&');
                    i+=4;
                }else if(strncmp(&text[i], "&gt;",4)==0){
                    ans.push_back('>');
                    i+=3;
                }else if(strncmp(&text[i], "&lt;",4)==0){
                    ans.push_back('<');
                    i+=3;
                }else if(strncmp(&text[i], "&frasl;",7)==0){
                    ans.push_back('/');
                    i+=6;
                }else{
                    ans.push_back(text[i]);
                }
            }else{
                ans.push_back(text[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

