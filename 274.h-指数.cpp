#include "s.h"
/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(),citations.end(),std::greater<int>());
        int i=0;
        for(;i<n;i++){
            if(citations[i]>i+1){
                continue;
            }else{
                break;
            }
        }
        return i;
    }
};
// @lc code=end

