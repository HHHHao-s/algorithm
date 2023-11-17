#include "s.h"
/*
 * @lc app=leetcode.cn id=2736 lang=cpp
 *
 * [2736] 最大和查询
 */

// @lc code=start
class SegmentTree { // 区间最大值线段树
private:
    vector<int> segmentTree;
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
    SegmentTree(vector<int>& nums) : n(nums.size()), segmentTree(nums.size() * 4) {
        build(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        change(index, val, 0, 0, n - 1);
    }

    int mxRange(int left, int right) {
        return range(left, right, 0, 0, n - 1);
    }
};


class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<int> ans;

        vector<pair<int,int>> nums;
        for(int i=0;i<nums1.size();i++){
            nums.push_back({nums1[i], nums2[i]});
        }
        sort(nums.begin(), nums.end(), [](const pair<int,int>&a, const pair<int,int>&b){
            if(a.first<b.first){
                return true;
            }else if(a.first==b.first){
                return a.second<b.second;
            }else{
                return false;
            }
        });

        vector<pair<int,int>> st;
        for(auto p:nums){
            while(!st.empty() && p.first>=st.back().first && p.second>=st.back().second){
                st.pop_back();
            }
            st.push_back(p);
        }
        
        vector<int> tmnums;
        for(auto [x,y]: st){
            tmnums.push_back(x+y);
            
        }
        SegmentTree sgtree(tmnums);

        for(int i=0;i<queries.size();i++){
            int query_x = queries[i][0];
            
            int query_y = queries[i][1];
            auto l = lower_bound(st.begin(),st.end(),pair<int,int>(query_x,query_y), [](const pair<int,int>&a, const pair<int,int>&b){
                return a.first<b.first;
            });
            if(l==st.end()){
                ans.push_back(-1);
                continue;
            }
            auto r = upper_bound(l,st.end(),query_y, [](int b, const pair<int,int>& a){
                return a.second<b;
            });
            if(r==l){
                ans.push_back(-1);
                continue;
            }
            r--;
            

            ans.push_back(sgtree.mxRange(l-st.begin(), r-st.begin()));

        }
        return ans;


    }
};
// @lc code=end

// int main(){

//     Solution s;
//     vector<int> nums1 = {4,3,1,2};
//     vector<int> nums2 = {2,4,9,5};
//     vector<vector<int>> qu={
//         {4,1},
//         {1,3},
//         {2,5}
//     };
//     printArr(s.maximumSumQueries(nums1, nums2, qu));

// }