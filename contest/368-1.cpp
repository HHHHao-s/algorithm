#include "../s.h"

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> pre(n),back(n);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i]= min(pre[i-1],nums[i]);
        }
        back[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            back[i] = min(back[i+1], nums[i]);
        }
        int a,b,c;
        for(int i=1;i<n-1;i++){
            a = pre[i-1];
            b = nums[i];
            c = back[i+1];
            if(a<b && b>c){
                ans = min(ans, a+b+c);
            }
        }
        return ans==INT_MAX?-1:ans;

        
    }
};