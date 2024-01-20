#include "s.h"
/*
 * @lc app=leetcode.cn id=1498 lang=cpp
 *
 * [1498] 满足条件的子序列数目
 */

// @lc code=start
class BITree{
public:
    BITree(const vector<int>& in_nums):nums(in_nums),info(in_nums.size()+1) {
        for (int i = 1; i <= in_nums.size(); i++) {
            info[i] += in_nums[i - 1];
            int nxt = i + (i & -i); // 下一个关键区间的右端点
            if (nxt <= in_nums.size()) {
                info[nxt] += info[i];
            }
        }
    }
    void increase(int index, int delta){
        nums[index]+=delta;
        index++;
        for(;index<info.size();index += (index&(-index))){
            info[index] += delta;
        
        }
    }
    void update(int index, int val){
        int delta = val-nums[index];
        nums[index] = val;
        index++;
        for(;index<info.size();index += (index&(-index))){
            info[index] += delta;
        
        }
    }
    // left==-1 会直接返回0
    int query(int index){
        int ret =0;
        index++;
        for(;index>0;index-=(index&(-index))){
            ret += info[index];
        }
        return ret;
    }
    //[left, right]
    int queryRange(int left, int right){ 
        
        return query(right)- query(left-1);
        
    }
private:
    vector<int> nums;
    vector<int> info;
    int n;
};

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        vector<int> tmp(1000001);
        
        BITree left(tmp);
        int n = nums.size();
        for(int i=n;i-->0;){
            tmp[nums[i]]++;
        }
        BITree right(tmp);
        long long ans = 0;
        
        const int MOD = 1e9+7;
        
        vector<long long> memo;
        long long cur=1;

        for(int i=0;i<=100000;i++){
            memo.push_back(cur);
            cur = (cur*2)%MOD;
        }

        for(int i=0;i<n;i++){
            int num = nums[i];
            right.increase(num, -1);
            if(num>target-num){
                left.increase(num, 1);
                continue;
            }
            long long right_bigger = right.queryRange(num+1, target-num);
            
            long long left_bigger = left.queryRange(num , target-num);
            ans  = (ans+memo[left_bigger+right_bigger])%MOD;
            
            left.increase(num, 1);
            
        }

        if(ans<0){
            ans += MOD;
        }
        return ans;

        


    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums= {7,10,7,3,7,5,4};
    cout<< s.numSubseq(nums, 12);
}