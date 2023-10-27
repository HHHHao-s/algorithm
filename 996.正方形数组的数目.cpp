#include "s.h"
/*
 * @lc app=leetcode.cn id=996 lang=cpp
 *
 * [996] 正方形数组的数目
 */

// @lc code=start
class Solution {
private:
    bool isPerfectSquare(int num) {
        int x = sqrt(num);
        return x * x == num;
    }   
    int ans{0};
    
    void backTrace(vector<int>& nums, int high, int n,int last){

        if(high==n){

            ans++;
            return ;
        }
        unordered_set<int> vis;
        for(int i=high;i<n;i++){
            if(isPerfectSquare(last+ nums[i]) &&!vis.count(nums[i])){
                vis.insert(nums[i]);

                swap(nums[i], nums[high]);
                backTrace(nums, high+1,n,nums[high]);
                swap(nums[i], nums[high]);

            }         
        }


    }

public:
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        
        unordered_set<int> vis;
        for(int i=0;i<n;i++){
            if(!vis.count(nums[i])){
                vis.insert(nums[i]);
                swap(nums[i],nums[0]);
                backTrace(nums,1,n,nums[0]);
                swap(nums[i],nums[0]);
            }
            
            
            
        }
        return ans;
    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int> nums={2,2,7};
    cout << s.numSquarefulPerms(nums);

}