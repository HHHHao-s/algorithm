#include "../s.h"


class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n-k+1);
        
        for(int i=0;i<n-k+1;i++){

            unordered_map<int,int> cnt;
            for(int j=i;j<i+k;j++){
                cnt[nums[j]]++;
            }
            vector<pair<int,int>> arr;
            for(auto [num,ct]: cnt){
                arr.push_back({ct, num});
            }
            sort(arr.begin(),arr.end(),greater<>());
            for(int j=0;j<x && j<arr.size();j++){
                ans[i] += arr[j].first * arr[j].second;
            }

        }
        return ans;

    }
};





