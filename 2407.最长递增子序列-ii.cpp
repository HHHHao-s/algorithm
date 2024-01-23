#include "s.h"
/*
 * @lc app=leetcode.cn id=2407 lang=cpp
 *
 * [2407] 最长递增子序列 II
 */

// @lc code=start
class SegmentTree { // 区间最大值线段树
private:
    vector<int> segmentTree;
    vector<int> nums;
    int n;

    void build(int node, int s, int e, vector<int> &nums) {
        if (s == e) {
            segmentTree[node] = nums[s];
            return;
        }
        int m = s + (e - s) / 2;
        build(node * 2 + 1, s, m, nums);
        build(node * 2 + 2, m + 1, e, nums);
        segmentTree[node] = max(segmentTree[node * 2 + 1] ,segmentTree[node * 2 + 2]);
    }

    void change(int index, int val, int node, int s, int e) {
        if (s == e) {
            segmentTree[node] = val;
            return;
        }
        int m = s + (e - s) / 2;
        if (index <= m) {
            change(index, val, node * 2 + 1, s, m);
        } else {
            change(index, val, node * 2 + 2, m + 1, e);
        }
        segmentTree[node] = max(segmentTree[node * 2 + 1] , segmentTree[node * 2 + 2]);
    }

    int range(int left, int right, int node, int s, int e) {
        if (left == s && right == e) {
            return segmentTree[node];
        }
        int m = s + (e - s) / 2;
        if (right <= m) {
            return range(left, right, node * 2 + 1, s, m);
        } else if (left > m) {
            return range(left, right, node * 2 + 2, m + 1, e);
        } else {
            return max(range(left, m, node * 2 + 1, s, m) , range(m + 1, right, node * 2 + 2, m + 1, e));
        }
    }

public:
    SegmentTree(vector<int>& _nums) : n(_nums.size()), segmentTree(_nums.size() * 4),nums(_nums) {
        build(0, 0, n - 1, _nums);
    }

    void increase(int index, int delta){
        nums[index]+=delta;
        change(index, nums[index], 0,0,n-1);
    }

    void update(int index, int val) {
        nums[index] = val;
        change(index, val, 0, 0, n - 1);
    }

    int mxRange(int left, int right) {
        if(left<0){
            left=  0;

        }
        if(right>n-1){
            right=n-1;
        }
        return range(left, right, 0, 0, n - 1);
    }
    int query(int index){
        return nums[index];
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        
        int index = 0;
        int n = nums.size();

        vector<int> digitDP(100001);
        SegmentTree st(digitDP);

        for(int i=0;i<n;i++){
            int num = nums[i];
            int len = st.mxRange(num-k, num-1);
            int origin = st.query(num);
            st.update(num, max(origin ,len+1));
        }

        return st.mxRange(0, 100000);
        
    }
};
// @lc code=end

