#include "s.h"
/*
 * @lc app=leetcode.cn id=2025 lang=cpp
 *
 * [2025] 分割数组的最多方案数
 */

// @lc code=start
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        long long sum = 0;
        int n = nums.size();
        vector<long long> presum, backsum(n);
        unordered_map<long long, int> can;
        for(int num:nums){
            sum+=num;
            presum.push_back(sum);
            can[sum]++;
        }
        
        sum=0;
        int ans = 0;
        for(int i=n;i-->0;){
            sum+=nums[i];
            backsum[i]=sum;
            if(i>0 && backsum[i]==presum[i-1]){
                ans++;
            }
        }
        long long total = presum[n-1];
        
        unordered_map<long long,int> lcan;
        can[total]--;
        // lcan[0]++;

        for(int i=0;i<n;i++){
            
            if(k!=nums[i]){
                int cnt=0;
                long long delta = k-nums[i];
                long long tmp_total = delta+total;
                if(tmp_total%2==0){
                    long long x = tmp_total/2-delta;
                    cnt+=can[x];
                    long long y = tmp_total/2;
                    cnt+=lcan[y];
                    
                    ans = max(ans, cnt);
                }
            }
            
            if(i<n){
                long long sum = presum[i];
                can[sum]--;
                lcan[sum]++;
            }
            

        }
        return ans;

    }
};
// @lc code=end

int main(){
    Solution s;
    // vector<int> nums = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30827,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> nums = {2,-1,2};
    cout << s.waysToPartition(nums, 3);
}