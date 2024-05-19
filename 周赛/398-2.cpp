#include "../s.h"


class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        vector<int> can(n);
        int last = nums[0]%2;
       
        int begin = 0;
        map<int ,int> rg;
        for(int i=1;i<n;i++){
            int num = nums[i];
            if(num%2==1){
                
                if(last == 1){
                    rg[begin] = i;
                    begin=i;
                }
                
                last = 1;
            }else{
                
                if(last == 0){
                    rg[begin] = i;
                    begin=i;
                }           
                last = 0;
            }
        }
        rg[begin ] =n;
        vector<bool> ret;
        for(auto &q: queries){
            int l = q[0];
            int r = q[1];
            auto p= --rg.upper_bound(l);
            if(p->second>r){
                ret.push_back(true);
            }else{
                ret.push_back(false);
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
    vector<int> nums= {1,8};
    vector<vector<int>> q={{1,1}};
    printArr( s.isArraySpecial(nums, q));
}