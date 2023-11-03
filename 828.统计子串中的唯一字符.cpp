#include "s.h"
/*
 * @lc app=leetcode.cn id=828 lang=cpp
 *
 * [828] 统计子串中的唯一字符
 */

// @lc code=start
class Solution {
public:
    int uniqueLetterString(string s) {
        int cur=0;
        int ans = 0;
        int n = s.size();
        vector<int> last(26,-1);
        vector<int> last2(26,-1);
        for(int i=0;i<n;i++){
            if(last[s[i]-'A']==-1){
                cur += i+1;
                ans += cur;
                
                last[s[i]-'A'] = i;
            }else{
                cur += i-last[s[i]-'A'];
                cur -= last[s[i]-'A']-last2[s[i]-'A'];
                ans += cur;
                last2[s[i]-'A'] = last[s[i]-'A'];
                last[s[i]-'A'] = i;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.uniqueLetterString("ABA");
    
}