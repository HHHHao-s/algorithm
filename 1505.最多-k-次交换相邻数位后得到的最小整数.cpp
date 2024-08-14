#include "s.h"
/*
 * @lc app=leetcode.cn id=1505 lang=cpp
 *
 * [1505] 最多 K 次交换相邻数位后得到的最小整数
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
    string minInteger(string num, int k) {

        vector<int> arr(num.size(),0);
        vector<deque<int>> pos(10);
        for(int i=0;i<num.size();i++){

            pos[num[i]-'0'].push_back(i);
        }
        string ret;

        BITree bi(arr);

        for(int i=0;i<num.size();i++){

            for(int j=0;j<10;j++){
                if(pos[j].empty()){
                    continue;
                }
                int p = pos[j].front();
                int deleted = bi.queryRange(0, p);
                if(p-deleted<=k){
                    ret.push_back(j+'0');
                    bi.update(p, 1);
                    pos[j].pop_front();
                    k-=(p-deleted);
                    break;
                }

            }

        }
        return ret;

    }
};
// @lc code=end

int main(){
    Solution s;
    cout <<s.minInteger("9000900", 3);
}
