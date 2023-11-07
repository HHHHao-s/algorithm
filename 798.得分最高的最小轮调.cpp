#include "s.h"
/*
 * @lc app=leetcode.cn id=798 lang=cpp
 *
 * [798] 得分最高的最小轮调
 */

// @lc code=start
class Solution {
public:
    int bestRotation(vector<int>& nums) {

        priority_queue<int,vector<int>, greater<int>> left, right;
        int n = nums.size();
        vector<int> diffs(n);
        int cnt=0;

        for(int i=0;i<n;i++){

            if(i-nums[i]>=0){
                cnt++;
                if(i-nums[i]+1<n)
                    diffs[i-nums[i]+1]--;
                if(i-nums[i]==0){
                    diffs[0]++;
                }
            }

            
        }
        
        int ans = 0;
        int ans_index=0;
        
        for(int k=0;k<n;k++){

            cnt+=diffs[k];
            
            if(cnt>ans){
                ans = cnt;
                ans_index = k;
            }
            cnt++;
            if(k+n-nums[k]+1<n){
                diffs[k+n-nums[k]+1]--;
            }
            
        }

        return ans_index;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums = {1,3,0,2,4};
    cout << s.bestRotation(nums);
}