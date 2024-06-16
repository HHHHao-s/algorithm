#include "../s.h"
class Solution {

public:

    int minimumDifference(vector<int>& nums, int k) {

        vector<int> p;
        int ret = 1e9;
        
        for(int i=0;i<nums.size();i++){
            int cur = nums[i];
            vector<int> tp{cur};
            for(auto each: p){
                if(cur >= k ){
                    ret = min(ret, cur-k);
                }else{
                    ret = min(ret, k-cur);
                }
                int next = each&cur;
                if(tp.back() == next){
                    cur = next;
                    continue;
                }
                tp.push_back(each & cur);
                cur = next;
            }
            if(cur >= k ){
                ret = min(ret, cur-k);
            }else{
                ret = min(ret, k-cur);
            }
            p = tp;
        }
        return ret;

    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,4,5};
    cout << s.minimumDifference(nums, 3);
}