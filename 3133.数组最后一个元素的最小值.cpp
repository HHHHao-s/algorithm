#include "s.h"
/*
 * @lc app=leetcode.cn id=3133 lang=cpp
 *
 * [3133] 数组最后一个元素的最小值
 */

// @lc code=start
class Solution {
public:
    long long minEnd(int n, int x) {
        long long ret = x;
        long long mx = n-1;
        long long bx = x;
        int ori = 0;
        for(int i=0;i<64;i++){
            
            while((bx & (1ll<<ori))){
                ori++;
            }
            if(mx & (1ll<<i))
                ret|=(1<<ori);
            ori++;
            if(mx < (1ll<<i)){
                return ret;
            }
            
        }
        return ret;


    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.minEnd(3, 4);
}