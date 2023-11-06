#include "s.h"
/*
 * @lc app=leetcode.cn id=947 lang=cpp
 *
 * [947] 移除最多的同行或同列石头
 */

// @lc code=start
class UnionFind{
private:
    unordered_map<int,int> par;
    int count{0};
public:
    int find(int x){
        if(par.count(x)==0){
            count++;
            par[x] = x;
            return x;
        }

        if(x!=par[x]){
            return par[x] = find(par[x]);
        }
        return x;
    }

    void merge(int x,int y){
        int fx = find(x);
        int fy = find(y);

        if(fx!=fy){
            par[fx] = fy;
            count--;
        }
    }
    int getCount(){
        return count;
    }


};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        UnionFind uf;
        for(auto &stone : stones){
            // 将行与列合并
            uf.merge(stone[0]+10001, stone[1]);
        }
        return stones.size()-uf.getCount();

    }
};
// @lc code=end

