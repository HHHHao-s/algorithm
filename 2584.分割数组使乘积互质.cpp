#include "s.h"
/*
 * @lc app=leetcode.cn id=2584 lang=cpp
 *
 * [2584] 分割数组使乘积互质
 */

// @lc code=start
class Solution {
public:
    int findValidSplit(vector<int>& nums) {

        unordered_map<int,int> left,right;
        vector<int> diff(nums.size());
        for(int i=0;i<nums.size();i++){
           int x = nums[i];
           // 分解质因数
           for(int j=2;j*j<=x;j++){
                while(x%j==0){
                    x/=j;
                    if(!left.count(j)){
                        left[j] = i;
                    }
                    right[j] = i;
                    
                }
           }
           if(x>1){
                if(!left.count(x)){
                    left[x] = i;
                }
                right[x] = i;
           }
           
        }
        for(auto [p, l]: left){
            diff[l]++;
            diff[right[p]]--;
        }

        
        int cur = 0;
        for(int i=0;i<nums.size()-1;i++){
            
            cur += diff[i];
            if(cur==0){
                return i;
            }
            
        }
        return -1;



    }
};
// @lc code=end

