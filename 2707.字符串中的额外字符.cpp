#include "s.h"
/*
 * @lc app=leetcode.cn id=2707 lang=cpp
 *
 * [2707] 字符串中的额外字符
 */

// @lc code=start
class Solution {

public:
    int minExtraChar(string s, vector<string>& dictionary) {

        unordered_set<string> st;
        for(auto &str: dictionary){
            st.insert(str);
        }
        vector<int> memo(s.size()+1, -1);
        function<int(int)> f=[&](int right){
            if(right<0){
                return 0;
            }
            if(memo[right]!=-1){
                return memo[right];
            }
            int ret=right+1;
            for(int j=right;j>=0;j--){
            
                for(int i=j;i>=0;i--){
                    if(st.count(s.substr(i, j-i+1))){
                        ret = min(ret, right-j+ f(i-1));
                    }
                }
            }
            

            memo[right]=ret;
            return ret;

        };

        return f(s.size()-1);

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<string> dic={
        "leet", "code", "leetcode"
    };
    cout<< s.minExtraChar("leetscode", dic);
}