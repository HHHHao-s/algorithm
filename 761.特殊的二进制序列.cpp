#include "s.h"
/*
 * @lc app=leetcode.cn id=761 lang=cpp
 *
 * [761] 特殊的二进制序列
 */

// @lc code=start
class Solution {
public:
    string makeLargestSpecial(string s) {
        
        int n = s.size();
        if(n<=2){
            return s;
        }
        int cnt= 0, left = 0;
        vector<string> subs;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
            }else{
                cnt --;
                if(cnt==0){

                    subs.push_back("1" + makeLargestSpecial(s.substr(left+1, i-left-1)) + "0");
                    left = i+1;
                }
            }
            

        }

        sort(subs.begin(),subs.end(), greater<>());
        return accumulate(subs.begin(), subs.end(), ""s);


    }
};
// @lc code=end

