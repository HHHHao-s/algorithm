#include "../s.h"

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<long long> store_pre(n);
        vector<long long> store_back(n);

        long long cur = nums[0];
        for(int i=1;i<n-1;i++){
            store_pre[i] = max(cur, (long long)nums[i-1]);
            cur = store_pre[i];

        }
        cur = nums[n-1];
        for(int i=n-1;i-->1;){
            store_back[i] = max(cur, (long long)nums[i+1]);
            cur = store_back[i];
        }
        long long ans=0;
        for(int i=1;i<n-1;i++){
            ans = max(ans, (store_pre[i]-nums[i])*store_back[i]);
        }

        return ans;

    }
};

int main(){

    Solution s;
    vector<int> nums={

        6,11,12,12,7,9,2,11,12,4,19,14,16,8,16
    };
    cout << s.maximumTripletValue(nums);


    return 0;
}