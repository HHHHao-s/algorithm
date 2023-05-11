#include "s.h"
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=2) return 0;

    
        int i=0,j=n-1;
        int left=height[i],right=height[j]; // 两边最高

        int ans = 0;
        do{


            // low = min(height[i], height[j]);

            if(height[i]<height[j]){
                i++;
                int x = height[i];
                // 左指针移动的情况
                if(x>=left){
                    left = x;
                     //覆盖
                }else{
                    ans += left-x;// 有空隙
                }

            }else{
                j--;
                int x = height[j];
                // 右指针移动的情况
                if(x>=right){
                    right = x;
                }else{
                    ans += right-x;// 有空隙
                }
                
            }



        }while(i<j);

        return ans;
    }
};
// @lc code=end

int main(){

    Solution s;

    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};

    printf("%d", s.trap(v));


    return 0;
}