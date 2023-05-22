#include "s.h"
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution{
public:

    
    char n2w[10][5] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };


    vector<string> letterCombinations(string digits){

        vector<string> ans;

        

        int p=0;
        int n = digits.size();
        int cursor[5] = {0};
        string cur;

        while(1){

            if(cursor[p]<strlen(n2w[digits[p]]))
                cur = cur + n2w[digits[p]][cursor[p]];
            else{ // roll back
                cur = cur.erase(cur.size()-1); 
                cursor[p]=0;
                p--;
                cursor[p]++;
                
            }
            
            if(p==n-1){// 
                ans.push_back(cur);                
                cur = cur.erase(cur.size()-1);                
                cursor[p]++;
                

            }else{
                
                p++;
                
            }
            

            
        }


    }
};
// @lc code=end

