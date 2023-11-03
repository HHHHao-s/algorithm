#include "s.h"
/*
 * @lc app=leetcode.cn id=899 lang=cpp
 *
 * [899] 有序队列
 */

// @lc code=start
class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size();
        // 大于等于二表明可以任意交换两个char的位置，让逆序变成正序
        if(k>=2){
            sort(s.begin(),s.end());
            return s;
        }else{
            int index=-1;
            string cur=s;
            
            for(int i=1;i<n;i++){
                string new_cur = s.substr(i, n-i);
                new_cur.append(s.substr(0, i));
                if(strcmp(new_cur.c_str(), cur.c_str())<0){
                    cur = new_cur;
                }

            }
             
            return cur;
        }
        return s;


    }
};
// @lc code=end

