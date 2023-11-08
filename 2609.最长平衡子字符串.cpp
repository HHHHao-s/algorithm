#include "s.h"
/*
 * @lc app=leetcode.cn id=2609 lang=cpp
 *
 * [2609] 最长平衡子字符串
 */

// @lc code=start
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        
        int a=0,b=0, ans=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                a++;
                ans =max(ans, 2*min(a,b));
            }else if( i==0 || s[i-1]=='1' ){
                a=0;
                b=1;
            }else{
                b++;
            }
        }

        return ans;

    }
};
// @lc code=end

int main(){


    Solution s;

    cout << s.findTheLongestBalancedSubstring("010001111000110110001101100000000111111");
}