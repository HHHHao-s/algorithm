#include "s.h"
/*
 * @lc app=leetcode.cn id=1147 lang=cpp
 *
 * [1147] 段式回文
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> memo;

    int dfs(string &text, int l, int r){
        if(l==r){
            return 1;
        }
        if(l>r){
            return 0;
        }
        char c = text[l];
        int res = 1;
        
        for(int i=r;i>l+(r-l)/2;i--){
            int sz = r-i+1;
            if(c == text[i]&&text.substr(l,sz)==text.substr(i,sz)){
                res = dfs(text, l+sz,i-1)+2;
                break;
            }
        }
        
        return res;


    }

public:
    int longestDecomposition(string text) {
        memo = vector<vector<int>>(text.size(), vector<int>(text.size(),-1));
        return dfs(text,0, text.size()-1);
    }
};
// @lc code=end

int main(){
    Solution s;

    cout << s.longestDecomposition("elvtoelvto");
}