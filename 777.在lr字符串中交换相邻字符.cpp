#include "s.h"
/*
 * @lc app=leetcode.cn id=777 lang=cpp
 *
 * [777] 在LR字符串中交换相邻字符
 */

// @lc code=start
class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i=0,j=0;
        while(i<n && j<n){
            while(i<n && start[i]=='X'){
                i++;
            }
            while(j<n && end[j]=='X'){
                j++;
            }
            if(i<n && j<n){
                if(start[i]==end[j]){
                    char c = start[i];
                    if ((c == 'L' && i < j) || (c == 'R' && i > j)) {
                        return false;
                    }
                    i++;
                    j++;
                }
                else{
                    return false;
                }
            }

        }

        for(;i<n;i++){
            if(start[i]!='X'){
                return false;
            }
        }
        for(;j<n;j++){
            if(end[j]!='X'){
                return false;
            }
        }

        return true;
        



        
    }
};
// @lc code=end

