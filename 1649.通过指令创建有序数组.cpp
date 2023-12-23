#include "s.h"
/*
 * @lc app=leetcode.cn id=1649 lang=cpp
 *
 * [1649] 通过指令创建有序数组
 */

// @lc code=start
class BITree{
public:
    BITree(const vector<int>& in_nums):nums(in_nums),info(in_nums.size()+1) {
        // for (int i = 1; i <= in_nums.size(); i++) {
        //     info[i] += in_nums[i - 1];
        //     int nxt = i + (i & -i); // 下一个关键区间的右端点
        //     if (nxt <= in_nums.size()) {
        //         info[nxt] += info[i];
        //     }
        // }
    }
    void update(int index){
        int delta = 1;
        nums[index]+=delta;
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
    int queryRange(int left, int right){ //[left, right]
        
        return query(right)- query(left-1);
        
    }
private:
    vector<int> nums;
    vector<int> info;
    int n;
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        vector<int> mp(100001, -1);
        vector<int> num;
        auto ori= instructions;
        sort(instructions.begin(), instructions.end());
        int n=0;
        for(int ins: instructions){
            if(mp[ins]==-1){
                num.push_back(ins);
                mp[ins]=n++;
            }
        }
        vector<int> tmp(n,0 );


        BITree bitree(tmp);
        int ans =0;
        const int MOD = 1e9+7;
        for(int ins:ori){
            if(mp[ins]==0 || mp[ins]==num.size()-1){
                bitree.update(mp[ins]);
                continue;
            }
            int l = bitree.queryRange(mp[num[0]], mp[ins]-1);
            int r = bitree.queryRange(mp[ins]+1, n-1);
            ans = (ans + min(l,r))%MOD;
            bitree.update(mp[ins]);
        }
        return ans;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> inss={1,3,3,3,2,4,2,1,2};
    cout << s.createSortedArray(inss);
}