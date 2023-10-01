#include "../s.h"


class Solution {
private:
    vector<long long> pre;
    unordered_map<long long, int> pre_map;
    int n;

    // long long get_between(int l, int r){
    //     if(l<r){
    //         return pre[r]-pre[l];
    //     }else if(l>r){
    //         return pre[n-1]+pre[r] - pre[l];
    //     }else{
    //         return -1;
    //     }
    // }

public:
    int minSizeSubarray(vector<int>& nums, int target) {
        n = nums.size();
        pre = vector<long long>(n);
        long long sum = 0;
        
        for(int i=0;i<n;i++){
            sum+= (long long)nums[i];
            pre_map[sum] = i;
            pre[i] = sum;
        }        

        

        if(target<=sum){
            int ans=INT_MAX;
            for(int i=0;i<n;i++){
                long long cur_pre=pre[i];
                // if(cur_pre == target){
                //     ans = min(ans, i+1);
                // }

                if(pre_map.count(cur_pre+target)){
                    ans = min(ans, abs(pre_map[cur_pre+target]-i));
                }
                if(pre_map.count(cur_pre+sum-target)){
                    ans = min(ans, n- pre_map[cur_pre+sum-target]+i);
                }
            }
            if(ans==INT_MAX){
                return -1;
            }else{
                return ans;
            }
        }else{
            int min_length = (target/sum)*n;
            target = target%sum;
            int ans=INT_MAX;
            for(int i=0;i<n;i++){
                long long cur_pre=pre[i];
                // if(cur_pre == target){
                //     ans = min(ans, i+1);
                // }

                if(pre_map.count(cur_pre+target)){
                    ans = min(ans, abs(pre_map[cur_pre+target]-i));
                }
                if(pre_map.count(cur_pre+sum-target)){
                    ans = min(ans, n- pre_map[cur_pre+sum-target]+i);
                }
            }
            if(ans==INT_MAX){
                return -1;
            }else{
                return min_length+ans;
            }
        }
        


    }
};

int main(){

    Solution s;
    vector<int> nums ={
        1,2,3
    };
    cout << s.minSizeSubarray(nums, 5);

    return 0;
}