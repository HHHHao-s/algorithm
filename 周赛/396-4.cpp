#include "../s.h"

class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        long long  mx = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        const long long MOD = 1e9+7;
        sort(nums.begin() , nums.end(), greater<>());
        if(cost2>=2*cost1){
            for(int num: nums){
                ans = (ans+(mx-num)*cost1 )%MOD;
            }
            if(ans <0){
                ans+=MOD;
                
            }
            return ans;
        }
        

        long long used = 0;
        long long last = 0;
        int cur = 0;
        for(int i=0;i<nums.size()-1;i++){
            int num = nums[i];
            num+=last;
            last = mx - num;
            used += mx-num;
            ans = (ans+ (mx-num)*cost2 )%MOD;
        }
        int last_num = nums.back();
        last_num+=last;
        if(mx-last_num <= used){
            if((mx-last_num) %2==0){
                ans = (ans+ ((mx-last_num)/2 * cost2)%MOD)%MOD;
            }else{
                
                ans = (ans+ ((mx-last_num)/2 * cost2)%MOD)%MOD;
                if((nums.size()-1) %2 ==0){
                    ans =( ans + min((long long)cost1,((long long)((nums.size()+1)/2*cost2 )))%MOD);
                }else{
                    ans = (ans+cost1)%MOD;
                }
            }
        }else{
            last_num+=used*2;
            long long mn =( mx-last_num)*cost1;
            for(int i=0;i<mx-last_num;i++){
                if((mx-last_num-i + nums.size() )%2==0 && (mx-last_num-i<nums.size()-1)){
                    mn = min(mn,(long long) (cost1*i + (mx-last_num-i + nums.size())/2*cost2)%MOD);
                }
            }
            ans =(ans + mn)%MOD;
        }
        if(ans <0){
            ans+=MOD;
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int > nums = {1,14,14,15};
    cout << s.minCostToEqualizeArray(nums, 2,1);
}