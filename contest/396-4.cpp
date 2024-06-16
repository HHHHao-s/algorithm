#include "../s.h"

class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        long long n = nums.size();
        long long  mx = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        const long long MOD = 1e9+7;
        sort(nums.begin() , nums.end());
        if(cost2>=2*cost1){
            for(int num: nums){
                ans = (ans+(mx-num)*cost1 )%MOD;
            }
            if(ans <0){
                ans+=MOD;       
            }
            
            return ans;
        } 
        long long sum = 0;
        for(int i=1;i<n;i++){
            sum += mx-nums[i];
        }
        ans = LONG_LONG_MAX;
        for(int i=0;i<1e6;i++){
            long long l = i+mx - nums[0];
            long long r = sum+(n-1)*i;
            long long tmp=0;
            if(l<=r){
                tmp = (l+r)/2*cost2;
                if((l+r)%2==1){
                    tmp += cost1;
                }
                
            }else{
                tmp = r*cost2;
                tmp = (tmp+ (l-r)*cost1 );
                
            }
            ans = min(ans, tmp);
        }
        
        return ans%MOD;
    }
};

int main(){
    Solution s;
    vector<int > nums = {1,14,14,15};
    cout << s.minCostToEqualizeArray(nums, 2,1);
}