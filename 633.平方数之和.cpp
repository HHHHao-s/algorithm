#include "s.h"
 /*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        
        int z= sqrt((double)c);
        for(int a=z;a>=0;a--){
            int b = c-a*a;
            if(((int)sqrt(b))*((int)sqrt(b)) ==b){
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

int main(){
    cout << Solution().judgeSquareSum(11);
}