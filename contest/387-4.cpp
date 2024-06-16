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
    vector<int> resultArray(vector<int>& nums) {


        vector<int> tmp = nums;
        int n = nums.size();
        sort(tmp.begin(),tmp.end());
        tmp.erase(unique(tmp.begin(),tmp.end()), tmp.end());

        int top=0;
        unordered_map<int,int> mp;

        for(int x :tmp){
            mp[x] = top++;
        }
        vector<int> r1,r2;
        vector<int> a1(top);
        vector<int> a2(top);
        int fsize=1, rsize=1;
        a1[mp[nums[0]]]++;
        a2[mp[nums[1]]]++;
        BITree b1(a1);
        BITree b2(a2);
        r1.push_back(nums[0]);
        r2.push_back(nums[1]);

        for(int i=2;i<n;i++){

            int num = nums[i];
            int l = b1.queryRange(mp[num]+1, top-1);
            int r= b2.queryRange(mp[num]+1, top-1);
            if(l >r ){
                b1.increase(mp[num], 1);
                r1.push_back(num);
                fsize++;
            }else if(l<r){
                b2.increase(mp[num], 1);
                r2.push_back(num);
                rsize++;
            }else if(l==r){
                if(fsize<=rsize){
                    b1.increase(mp[num], 1);
                    r1.push_back(num);
                    fsize++;
                }else if(fsize>rsize){
                    b2.increase(mp[num], 1);
                    r2.push_back(num);
                    rsize++;
                }
            }

        }

        for(int x: r2){
            r1.push_back(x);
        }
        return r1;


    }
};

