#include "common.h"
/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:

    vector<int> p; // 并查集，存储位置
    int cnt[100100]; // 并查集的拓展，用来存根节点的内容（数量）

    int find(int x){
        return p[x]==x?x:(p[x] = find(p[x]));
    }

    void insert(int x,int y){
        // y合并到x
        cnt[find(x)] += cnt[find(y)];
        p[find(y)] = find(x);

    }


    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            cnt[i] = 1;
            p.push_back(i);
        }

        unordered_map<int,int> umap;

        for(int i=0;i<n;i++){
            int j = nums[i];
            if(umap.count(j))continue;// 重复
            if(umap.count(j-1)) insert(i, umap[j-1]);
            if(umap.count(j+1)) insert(i, umap[j+1]);
            
            umap.insert({j,i});


        }


        int ans = 1;

        for(int i=0;i<n;i++){
            ans = max(ans, cnt[i]);
        }

        return ans;


    }
};



// @lc code=end

