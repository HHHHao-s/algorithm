#include "../s.h"


class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        
        
        int n = nums.size();
        vector<pair<int,int>> max_vec(n);
        vector<pair<int,int>> min_vec(n);
        max_vec[n-1] = {nums[n-1], n-1};
        min_vec[n-1] = {nums[n-1], n-1};

        for(int i=n-1;i-->0;){
            int x = nums[i];
            if(x>max_vec[i+1].first){
                max_vec[i] = {x,i};
            }else{
                max_vec[i] = max_vec[i+1];
            }
            if(x<min_vec[i+1].first){
                min_vec[i] = {x,i};
            }else{
                min_vec[i] = min_vec[i+1];
            }
        }

        for(int i=0;i<n-indexDifference;i++){
            
            int max_ = max_vec[i+indexDifference].first;
            int min_ = min_vec[i+indexDifference].first;
            int num = nums[i];
            if(abs((long long)num-(long long)max_)>=valueDifference){
                return {i, max_vec[i+indexDifference].second};
            }
            if(abs((long long)num-(long long)min_)>=valueDifference){
                return {i, min_vec[i+indexDifference].second};
            }
        }
        return {-1,-1};

    }
};

int main(){
    Solution s;

    vector<int> nums={
        5,1,4,1
    };
    printArr(s.findIndices(nums,2,4));

    return 0;
}