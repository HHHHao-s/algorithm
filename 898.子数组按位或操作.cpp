#include "s.h"
/*
 * @lc app=leetcode.cn id=898 lang=cpp
 *
 * [898] 子数组按位或操作
 */

// @lc code=start
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        vector<int> ors;
        unordered_set<int> nums;
        for(int i=n-1;i>=0;i--){
            ors.push_back(0);
            ors[0] |= arr[i];
            int k = 0;
            for(int j=1;j<ors.size();j++){
                ors[j] |= arr[i];
                // 原地去重
                if(ors[k]==ors[j])
                    continue;
                else
                    ors[k++] = ors[j];
            }
            ors.resize(k+1);
            for(auto num:ors){
                nums.insert(num);
            }
        }
        
        return nums.size();


    }
};
// @lc code=end

