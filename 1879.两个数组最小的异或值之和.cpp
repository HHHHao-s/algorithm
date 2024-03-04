#include "s.h"
/*
 * @lc app=leetcode.cn id=1879 lang=cpp
 *
 * [1879] 两个数组最小的异或值之和
 */

// @lc code=start
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        vector<int> f(1<<n, INT_MAX);
        f[0] = 0;
        for(int mask=1;mask<(1<<n);mask++){

            for(int i=0;i<n;i++){
                if(mask &(1<<i)){
                    f[mask] = min(f[mask], f[mask ^ (1<<i)]+ (nums1[__builtin_popcount(mask)-1]^(nums2[i])));
                }
            }


        }        

        return f[(1<<n) -1];
    }
};
// @lc code=end

