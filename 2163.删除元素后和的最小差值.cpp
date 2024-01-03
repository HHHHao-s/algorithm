#include "s.h"
/*
 * @lc app=leetcode.cn id=2163 lang=cpp
 *
 * [2163] 删除元素后和的最小差值
 */

// @lc code=start
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;

        long long left=0, right=0;
        map<int ,int > exist1, exist2, candidate;


        for(int i=0;i<n;i++){
            exist1[nums[i]]++;
            left+=nums[i];
        }
        for(int i=3*n;i-->n;){
            candidate[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            right+=candidate.rbegin()->first;
            exist2[candidate.rbegin()->first]++;
            candidate[candidate.rbegin()->first]--;
            if(candidate[candidate.rbegin()->first]==0){
                candidate.erase(candidate.rbegin()->first);
            }
        }
        long long ans = left-right;

        for(int i=n;i<2*n;i++){
            if(nums[i]<exist1.rbegin()->first){
                exist1[exist1.rbegin()->first]--;
                left-=exist1.rbegin()->first;
                if(exist1[exist1.rbegin()->first]==0){
                    exist1.erase(exist1.rbegin()->first);
                }
                exist1[nums[i]]++;
                left+=nums[i];
            }
            if(exist2.count(nums[i])){
                exist2[nums[i]]--;
                right-=nums[i];
                if(exist2[nums[i]]==0){
                    exist2.erase(nums[i]);
                    
                }
                exist2[candidate.rbegin()->first]++;
                right+=candidate.rbegin()->first;
                candidate[candidate.rbegin()->first]--;
                if(candidate[candidate.rbegin()->first]==0){
                    candidate.erase(candidate.rbegin()->first);
                }
            }else{
                candidate[nums[i]]--;
                if(candidate[nums[i]]==0){
                    candidate.erase(nums[i]);
                }
            }
            ans = min(ans, left-right);
        }
        return ans;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums= {21,23,6,9,42,43,47,15,42,22,46,43,11,46,20,6,50,45,31,43,16,39,1,47};
    cout << s.minimumDifference(nums);
}