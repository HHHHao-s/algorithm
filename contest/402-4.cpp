#include "../s.h"


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
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int> ret;

        vector<int> is(nums.size());
        for(int i=1;i<is.size()-1;i++){

            if(nums[i-1]< nums[i] && nums[i] > nums[i+1]){
                is[i] = 1;
            }

        }

        BITree b(is);

        for(auto q: queries){

            int a = q[0];
            int l = q[1];
            int r = q[2];
            if(a==1){
                if(l+1 <= r-1){
                    ret.push_back(b.queryRange(l+1, r-1));
                }else{
                    ret.push_back(0);
                }
                
            }else{
                nums[l] = r;
                if(l>0 && l<is.size()-1){
                    if(nums[l] >nums[l-1] && nums[l]> nums[l+1]){
                        b.update(l, 1);
                    }else{
                        b.update(l, 0);
                    }
                }
                l = l-1;
                if(l>0 && l<is.size()-1){
                    if(nums[l] >nums[l-1] && nums[l]> nums[l+1]){
                        b.update(l, 1);
                    }else{
                        b.update(l, 0);
                    }
                }
                l=l+2;
                if(l>0 && l<is.size()-1){
                    if(nums[l] >nums[l-1] && nums[l]> nums[l+1]){
                        b.update(l, 1);
                    }else{
                        b.update(l, 0);
                    }
                }
            }
        }
        return ret;


    }
};