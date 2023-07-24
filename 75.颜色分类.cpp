#include "s.h"
/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
         int n = nums.size();
         if(n==1){
         	return;
		 }
         int j=-1;
         
         for(int i=0;i<n;i++){
         	if(nums[i]==0){
         		int tmp = nums[++j];
         		nums[j] = 0;
         		nums[i] = tmp;
			}
		 }
		 j=n;
		 for(int i=n;i-->0;){
		 	if(nums[i]==2){
		 		int tmp = nums[--j];
		 		nums[j] = 2;
		 		nums[i] = tmp;
			 }
		 }
         
    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int> test{2,0,2,1,1,0};
    s.sortColors(test);
    printArr(test);


    return 0;
}