#include "s.h"
/*
 * @lc app=leetcode.cn id=2382 lang=cpp
 *
 * [2382] 删除操作后的最大子段和
 */

// @lc code=start
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        map<int,int> range;
        vector<long long> presum(n+1);
        map<long long,int> ans;
        
        range[0] = n;
        for(int i=0;i<n;i++){
            presum[i+1] = presum[i]+nums[i];
        }
        vector<long long> ret;
        ans[presum[n]]++;
        for(int i=0;i<n-1;i++){

            int remove_index = removeQueries[i];
            int l = (--range.upper_bound(remove_index))->first;
            int r = range[l];
            long long cur = presum[r] - presum[l];
            ans[cur]--;
            if(ans[cur]==0){
                ans.erase(cur);
            }
            range.erase(l);
            if(remove_index!=l){
                long long lsum = presum[remove_index] - presum[l];
                ans[lsum]++;
                range[l] = remove_index;
            }

            if(remove_index+1!=r){
                long long rsum = presum[r] - presum[remove_index+1];
                ans[rsum]++;
                range[remove_index+1] = r;
            }
            
            ret.push_back(ans.rbegin()->first);
            
            
        } 
        ret.push_back(0);
        return ret;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums = {1,2,5,6,1};
    vector<int> qs={0,3,2,4,1};
    printArr(s.maximumSegmentSum(nums, qs));
}