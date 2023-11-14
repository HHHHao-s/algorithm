#include "s.h"
/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
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

    int query(int index){
        
        int ret =0;
        index++;
        for(;index>0;index-=(index&(-index))){
            ret += info[index];
        }
        return ret;

    }

private:
    vector<int> nums;
    vector<int> info;
    int n;

};

class NumArray {
public:
    NumArray(vector<int>& nums):bitree(nums) {

    }
    
    void update(int index, int val) {

        bitree.update(index, val);

    }
    
    int sumRange(int left, int right) {

        return bitree.query(right)-bitree.query(left-1);

    }
private:
    BITree bitree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

int main(){
    vector<int> arr={1,3,5,7,9,11,13,17};
    NumArray num_arr(arr);
    for(int i=0;i<arr.size();i++){
        cout << num_arr.sumRange(0, i);
    }

}