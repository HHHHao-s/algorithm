#include "s.h"
/*
 * @lc app=leetcode.cn id=3165 lang=cpp
 *
 * [3165] 不包含相邻元素的子序列的最大和
 */

// @lc code=start
struct _Node{
    long long l, r, lr, nlr;
};

class SegmentTree { // 区间最大值线段树
private:
    vector<_Node> segmentTree;
    int n;

    void update(int node){
        auto &l = segmentTree[node * 2 + 1];
        auto &r = segmentTree[node * 2 + 2];
        segmentTree[node].l = max(l.l+r.l, l.lr+r.nlr);
        segmentTree[node].r = max(l.r+r.r, l.nlr+r.lr);
        segmentTree[node].lr= max(l.lr+ r.r, l.l+r.lr);
        segmentTree[node].nlr= max(l.r+r.nlr, l.nlr+r.l);

    }

    void build(int node, int s, int e, vector<int> &nums) {
        if (s == e) {

            
            segmentTree[node] = {0,0,max(nums[s],0), 0};
            return;
        }
        int m = s + (e - s) / 2;
        build(node * 2 + 1, s, m, nums);
        build(node * 2 + 2, m + 1, e, nums);
        update(node);
    }

    void change(int index, int val, int node, int s, int e) {
        if (s == e) {

            segmentTree[node] = {0,0,max(val,0), 0};
            return;
        }
        int m = s + (e - s) / 2;
        if (index <= m) {
            change(index, val, node * 2 + 1, s, m);
        } else {
            change(index, val, node * 2 + 2, m + 1, e);
        }
        update(node);
    }

    

public:
    SegmentTree(vector<int>& nums) : n(nums.size()), segmentTree(nums.size() * 4) {
        build(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        change(index, val, 0, 0, n - 1);
    }

    long long get(){
        return max({segmentTree[0].l, segmentTree[0].r, segmentTree[0].lr, segmentTree[0].nlr});
    }
};

class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {

        const long long MOD = 1e9+7;
        long long ans=0;

        SegmentTree sg(nums);

        for(auto &q: queries){
            sg.update(q[0], q[1]);
            ans +=sg.get();

        }
        ans = (ans+MOD)%MOD;
        return ans;

    }
};
// @lc code=end

int main(){
    vector<int> nums= {3,3,3};
    vector<vector<int>> q{
        {2,0},
        {1,0}
    };
    cout << Solution().maximumSumSubsequence(nums, q);
}