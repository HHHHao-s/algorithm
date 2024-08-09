#include "s.h"
/*
 * @lc app=leetcode.cn id=3132 lang=cpp
 *
 * [3132] 找出与数组相加的整数 II
 */

// @lc code=start
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int x = INT_MAX;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n = nums1.size();

        for(int i = 0;i<n-1;i++){

            for(int j=i+1;j<n;j++){
                int next = 0;
                int ans = INT_MAX;
                int can = 1;
                for(int k=0;k<n;k++){
                    if(k!=i && k!=j){
                        int diff = nums2[next] - nums1[k];
                        if(ans !=INT_MAX && diff!=ans){
                            can = 0;
                            break;
                        }else{
                            ans = diff;
                        }
                        next++;
                    }
                    
                }
                if(can){
                    x = min(x, ans);
                }

            }
        }
        return x;


    }
};
// @lc code=end

