#include "s.h"
/*
 * @lc app=leetcode.cn id=1955 lang=cpp
 *
 * [1955] 统计特殊子序列的数目
 */

// @lc code=start
class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {

        int a=0,b=0,c=0;
        const int MOD = 1e9+7;

        int ans =0 ;
        for(int x: nums){

            if(x==0){
                a = ((2*a)%MOD +1)%MOD;
            }else if(x==1){
                b = ((2*b)%MOD +a)%MOD;
                
            }else if(x==2){
                c = ((2*c)%MOD +b)%MOD;
            }

        }

        return c;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums = {0,1,2,2};
    cout << s.countSpecialSubsequences(nums);
}