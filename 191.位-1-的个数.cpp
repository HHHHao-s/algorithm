#include "s.h"
/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
private:
    const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
    const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
    const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
    const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

public:
    int hammingWeight(uint32_t n) {
        
        
        n = ((n>>1) & M1) + (n&M1);
        n = ((n>>2) & M2) + (n&M2);
        n = ((n>>4) & M4) + (n&M4);
        n = ((n>>8) & M8) + (n&M8);
        return (n>>16)+(n&(0xffff));



    }
};
// @lc code=end

int main(){

    Solution s;
    cout << s.hammingWeight(UINT32_MAX-1);

}