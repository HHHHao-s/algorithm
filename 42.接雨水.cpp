#include "common.h"
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


        vector<int> water={0}; // 每一列的水量

        for(int i=0;i<n;i++){
            water.push_back(0);
        }

        

        int i=0,j=n-1;
        int left=height[i],right=height[j]; // 两边最高

        int low=0;

        do{


            // low = min(height[i], height[j]);

            if(height[i]<height[j]){
                i++;
                int x = height[i];
                // 左指针移动的情况
                if(x>=left){
                    left = x;
                    water[i] = 0; //覆盖
                }else{
                    water[i] = left-x;// 有空隙
                }

            }else{
                j--;
                int x = height[j];
                // 右指针移动的情况
                if(x>=right){
                    right = x;
                    water[j] = 0; //覆盖
                }else{
                    water[j] = right-x;// 有空隙
                }
                
            }



        }while(i<j);

        
        return accumulate(water.begin(),water.end(),0);


    }
};
// @lc code=end

int main(){

    Solution s;

    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};

    printf("%d", s.trap(v));


    return 0;
}