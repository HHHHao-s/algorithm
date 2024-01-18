#include "s.h"
/*
 * @lc app=leetcode.cn id=2179 lang=cpp
 *
 * [2179] 统计数组中好三元组数目
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
    void update(int index, int val){
        int delta = val-nums[index];
        nums[index] = val;
        index++;
        for(;index<info.size();index += (index&(-index))){
            info[index] += delta;
        
        }
    }
    // left==-1 会直接返回0,[0,index]
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
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> mp(n);
        vector<int> all_zero(n);
        BITree bitree(all_zero);


        for(int i=0;i<n;i++){

            mp[nums1[i]] = i;

        }

        vector<long long> smaller(n), bigger(n);
        for(int i=0;i<n;i++){

            nums2[i] = mp[nums2[i]];
            
            smaller[nums2[i]]=bitree.query(nums2[i]-1);
            
            bitree.update(nums2[i], 1);
        }
        bitree = BITree(all_zero);
        for(int i=n;i-->0;){
            bigger[nums2[i]]=bitree.queryRange(nums2[i]+1, n-1);
            bitree.update(nums2[i], 1);
        }
        long long ans=0;
        for(int i=1;i<n-1;i++){
            ans += smaller[nums2[i]]*bigger[nums2[i]];
        }
        return ans;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums1={2,0,1,3},nums2={0,1,2,3};
    cout << s.goodTriplets(nums1, nums2);
}