#include "../s.h"

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();        
        vector<long long> dp1(n+1,0),dp2(n+1,0);
        
        map<long long, int> m_pos;
        bool all_d=1;
        int max_it = INT_MIN;
        for(int i =0;i<n;i++){
            max_it=max(max_it, nums[i]);
        }
        if(max_it <= 0){
            return max_it;
        }
        dp1[0] = nums[0];
        dp2[0] = 0;
        m_pos[nums[0]] = 0;

        for(int i=1;i<n;i++){
            long long num = nums[i];
            auto it = m_pos.upper_bound(num);
            dp1[i] = num;
            if(it==m_pos.begin()){
                dp1[i] = num;
                dp2[i] = max(dp1[i-1],dp2[i-1]);
            }else{
                it--;
                while(1){

                    if(num-it->first>=i-it->second){
                        dp1[i] = max(dp1[i],num+dp1[it->second]);                        
                    }
                    if(it==m_pos.begin()){
                        break;
                    }
                    it--;
                }
                
            }
            dp2[i] = max(dp1[i-1],dp2[i-1]);
            
            m_pos[num] = i;

        }
        return max(dp1[n-1],dp2[n-1] );
    }
};

int main(){
    Solution s;

    vector<int> nums={31,-3,22,28,-49,-38,29,-9,-41,-17,22,-33,-1,-35,44,28,40,28,-37,12,-21,6,36,-36,1,12,27,31,15,-19,46};
    cout << s.maxBalancedSubsequenceSum(nums);

}