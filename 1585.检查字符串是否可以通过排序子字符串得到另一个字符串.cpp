#include "s.h"
/*
 * @lc app=leetcode.cn id=1585 lang=cpp
 *
 * [1585] 检查字符串是否可以通过排序子字符串得到另一个字符串
 */

// @lc code=start
class Solution {
public:
    bool isTransformable(string s, string t) {
        

        vector<int> diff(10);
        for(int i=0;i<s.size();i++){
            diff[s[i]-'0']++;
            diff[s[i]-'0']--;

        }
        for(int i=0;i<10;i++){
            if(diff[i]!=0){
                return false;
            }
        }

        vector<deque<int>> a(10);

        vector<int> b(10);

        for(int i=0;i<s.size();i++){
            a[s[i]-'0'].push_back(i);
        }

        for(int i=0;i<s.size();i++){

            int num = t[i]-'0';
            int p = a[num].front();
            a[num].pop_front();
            for(int j=0;j<num;j++){
                if(!a[j].empty() && a[j].front()<p){
                    return false;
                }

            }



        }
        return true;
    }
};
// @lc code=end

