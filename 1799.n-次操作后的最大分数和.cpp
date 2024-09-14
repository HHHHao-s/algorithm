#include "s.h"
/*
 * @lc app=leetcode.cn id=1799 lang=cpp
 *
 * [1799] N 次操作后的最大分数和
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size()/2;
        int ret= 0;
        vector<int> have(2*n);
        auto dfs =  [&](auto &&dfs, int big, int last, int  cur)->void{
            if(last==0){

                ret = max(cur, ret);
                return;
            }
            for(int i=1;i<2*n;i++){
                if(have[i]){
                    continue;
                }
                for(int j=0;j<i;j++){
                    if(have[j]){
                        continue;
                    }
                    if(gcd(nums[i],nums[j])>big){
                        continue;
                    }else if((1+last)*(last)/2 * gcd(nums[i],nums[j]) + cur<=ret){
                        continue;
                    }else{
                        have[i] = 1;
                        have[j] =1;
                        dfs(dfs, gcd(nums[i],nums[j]), last-1, cur+last*gcd(nums[i],nums[j]));
                        have[i] =0;
                        have[j] =0;
                    }
                }
            }

        };

        dfs(dfs, 0x7fffffff, n, 0);
        return ret;
    }   
};
// @lc code=end
int main(){
    Solution s;
    vector<int> nums= {1,2,3,4,5,6};
    cout << s.maxScore(nums);
}