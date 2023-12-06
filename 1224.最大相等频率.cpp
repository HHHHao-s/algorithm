#include "s.h"
/*
 * @lc app=leetcode.cn id=1224 lang=cpp
 *
 * [1224] 最大相等频率
 */

// @lc code=start
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int mx_len=0;
        unordered_map<int, int> num_cnt;
        unordered_map<int, int> cnt_cnt;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            if(num_cnt.count(num)!=0){
                cnt_cnt[num_cnt[num]]--;
                if(cnt_cnt[num_cnt[num]]==0){
                    cnt_cnt.erase(num_cnt[num]);
                }
            }
            num_cnt[num]++;
            cnt_cnt[num_cnt[num]]++;
            
            if(cnt_cnt.size()!=2){
                if(cnt_cnt.size()==1 && cnt_cnt.begin()->first==1){
                    mx_len = i+1;
                }else if(cnt_cnt.size()==1 && num_cnt.size()==1){
                    mx_len = i+1;
                }
                continue;
            }
            auto it = cnt_cnt.begin();
            auto it2 = ++cnt_cnt.begin();
            
            if(it->first-it2->first==1 && it->second==1){
                mx_len = i+1;
            }else if((it->first==1 && it->second==1) || (it2->first==1 && it2->second==1)){
                mx_len = i+1;
            }else if(it2->first-it->first==1 && it2->second ==1){
                mx_len = i+1;
            }

        }
        return mx_len;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums={
        
    };
    cout<< s.maxEqualFreq(nums);
}