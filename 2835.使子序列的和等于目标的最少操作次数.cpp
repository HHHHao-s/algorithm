#include "s.h"
/*
 * @lc app=leetcode.cn id=2835 lang=cpp
 *
 * [2835] 使子序列的和等于目标的最少操作次数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<long long > ct(32,0);
        long long sum = 0;
        for(int num:nums){
            int pos = log2(num);
            ct[pos] ++;
            sum += num;
        }
        if(sum<target){
            return -1;
        }
        int ret = 0;
        long long carry = 0;
        for(int i=0;i<32;i++){
            
            if(target & (1<<i)){
                if(ct[i]>=1){
                    carry = carry+ (ct[i]-1)*(1<<i);
                    ct[i] = 1;
                    
                    continue;
                }else{
                    if(carry>=(1<<i)){
                        carry-=(1<<i);
                        ct[i] =1;
                    }else{
                        for(int j=i;j<32;j++){
                            if(ct[j]>=1){
                                int k=j;
                                while(k>i){
                                    ct[k]--;
                                    k--;
                                    ct[k]+=2;
                                    ret++;
                                }
                                break;
                            }
                        }
                        carry+=(1<<i)*(ct[i]-1);
                        ct[i] = 1;
                    }

                }
            }else{
                carry+=ct[i]*(1<<i);
            }

        }
        return ret;


    }
};
// @lc code=end

