#include "s.h"
/*
 * @lc app=leetcode.cn id=955 lang=cpp
 *
 * [955] 删列造序 II
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // 模拟 判断一下有多少位是满足升序的
        int n = strs.size();
        int len = strs[0].size();
        vector<int> vis(n);
        int DeleteCnt = 0;
        for(int i = 0; i < len; i++) { // 遍历的列
            vector<int> tempVis(vis);
            bool needDelete = false;
            for(int j = 1; j < n; j++) { //遍历的行
                if(tempVis[j]) continue;
                // 逆序 直接删除
                if(strs[j-1][i] > strs[j][i]){
                    needDelete = true;
                    break;
                }else if(strs[j-1][i] < strs[j][i]){
                    // 正序 后续都不需要再比较
                    tempVis[j] = 1;
                } 
            }
            if(needDelete) DeleteCnt++;
            else vis = tempVis;
        }
        return DeleteCnt;
    }
};

// @lc code=end

