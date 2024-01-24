#include "s.h"
/*
 * @lc app=leetcode.cn id=2659 lang=cpp
 *
 * [2659] 将数组清空
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
    // left==-1 会直接返回0 [0,index]
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
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n, 1);
        BITree bt(presum);
        long long ans = 0;

        map<int, int> pos;

        for(int i=0;i<n;i++){
            pos[nums[i]] = i; 
        }
        int cur = 0;
        
        for(int i=0;i<n;i++){
            int next = pos.begin()->second;
            pos.erase(pos.begin()->first);
            int left =0, right = 0;
            if(next==cur){
                ans++;
            }else if(next>cur){
                right = bt.queryRange(cur, next-1);
                ans+=right+1;
            }else{
                left = bt.query(next-1);
                right = bt.queryRange(cur, n-1);
                ans+=left+right+1;
            }
            bt.update(next, 0);
            cur = (next+1)%n;

        }
        return ans;


    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums = {11,2,3,5,4,9,10};
    cout<<s.countOperationsToEmptyArray(nums);
}