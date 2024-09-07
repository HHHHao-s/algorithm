#include "s.h"
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ret= 1;

        vector<set<int>> dp2(k+1);
        vector<map<int,int>> dp3(k+1);

        for(int i=0;i<n;i++){
            int cur = dp3[0][nums[i]] + 1; 

            
            for(int l=k;l>=1;l--){
                int b =-1;
                if(!dp2[l-1].empty()){
                    b = *dp2[l-1].rbegin() +1;
                }
                if(dp3[l].count(nums[i])!=0){
                    b =max(b, dp3[l][nums[i]]+1);
                }
                if(b==-1){
                    continue;
                }
                
                dp3[l][nums[i]] = b;
                dp2[l].insert(b);
                ret = max(b, ret);
            }
            dp3[0][nums[i]] = cur;
            dp2[0].insert(cur);
            ret = max(ret, cur);
        }

        return ret;

    }
};

int main(){
    Solution s;
    vector<int> nums={28,29,29};

    cout<< s.maximumLength(nums, 1);
}