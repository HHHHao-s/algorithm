#include "../s.h"

class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {

        int ans=0, mask=0;
        int n = nums.size();
        for(int i=29;i>=0;i--){
            mask |= (1<<i);
            int index = 0;
            int cnt = 0;
            while(index<n){
                int cur = nums[index] & mask;
                int next = index+1;
                while(next<n && cur!=0){
                    cur&=nums[next]&mask;
                    next++;
                    cnt++;
                }
                index = next;
                if(cur!=0){
                    cnt++;
                }

            }
            if(cnt>k){
                mask &= ~(1<<i);
                ans |= (1<<i);
            }
        }
        return ans;

    }
};