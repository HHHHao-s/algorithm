#include <common.h>
/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> num_set;

        for(auto it: nums){
            num_set.insert(it);
        }

        int max_len = 0;

        for(auto &it: num_set){
            if(!num_set.count(it-1)){ // 如果此数的上一个和这个连续，那么就不是我们要的
                int current_num = it;
                int current_len = 1;
                int it2 = it;
                while(num_set.count(it2+1)){
                    it2++;
                    current_len++;
                }

                max_len = max(current_len, max_len);
            }
        }

        return max_len;

    }
};
// @lc code=end

