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
        if(digits.size()==0) return ans;
        int p=0;
        int n = digits.size();
        int cursor[5] = {0};
        char cur[5]={0};
        int cur_size = 0;
        while(1){

            if(cursor[p]<strlen(n2w[digits[p]-'0'])){
                
                cur[cur_size++] = n2w[digits[p]-'0'][cursor[p]];
                cur[cur_size] = 0;

            }else{ // roll back
                
                cursor[p]=0;
                p--;
                if(p<0){
                    break;// terminate
                }
                cur_size--;
                cursor[p]++;
                continue;

            }          
            if(p==n-1){
                ans.push_back(cur);                
                cur_size--;              
                cursor[p]++;
            }else{              
                p++;             
            }
                  
        }
        return ans;
    }
};
// @lc code=end
int main(){

    Solution s;
    string in = "23";
    cout << in;
    for(auto it:s.letterCombinations(in)){
        cout<< it <<" ";
    }

    return 0;
}
