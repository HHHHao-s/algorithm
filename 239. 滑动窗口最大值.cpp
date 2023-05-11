#include "s.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if(n==1 ){
            ans.push_back(nums[0]);
            return ans;
        }
        deque<int> q; // 存放下标的双向队列

        for(int i=0;i<k;i++){
            while(!q.empty() && nums[i]>=nums[q.back()]){
                q.pop_back();
            }

            q.push_back(i);
        }

        ans.push_back(nums[q.front()]);
        for(int i=k;i<n;i++){
            while(!q.empty() && nums[i]>=q.back()){
                q.pop_back();
            }
            q.push_back(i);

            while(q.front()<i-k){ // 弹队首
                q.pop_front();
            }

            ans.push_back(nums[q.front()]);


        }

        return ans;






    }
};