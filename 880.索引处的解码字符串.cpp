#include "s.h"
/*
 * @lc app=leetcode.cn id=880 lang=cpp
 *
 * [880] 索引处的解码字符串
 */

// @lc code=start
class Solution {
private:
    char dfs(string &s, int k, int n){
        
        long long cur = 0;

        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                int tmp_cur=cur;
                cur*=s[i]-'0';
                if(cur==k){
                    for(int j=i;j-->0;){
                        if(isalpha(s[j])){
                            return s[j];
                        }
                    }
                }else if(cur>k){
                    int want = k%(tmp_cur);
                    if(want==0){
                        for(int j=i;j-->0;){
                            if(isalpha(s[j])){
                                return s[j];
                            }
                        }
                    }else{
                        return dfs(s, want, n-1);
                    }
                    
                }
            }else{

                cur++;
                if(cur==k){
                    return s[i];
                }
            }
        }
        return '?';
    }

public:
    string decodeAtIndex(string s, int k) {
        // 删除前置数字
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                continue;
            }else {
                s = s.substr(i, s.size()-i);
                break;
            }
        }
        return {dfs(s, k, s.size())};
        

    }
};
// @lc code=end

int main(){
    Solution s;

    cout << s.decodeAtIndex("h2a28", 16);
}