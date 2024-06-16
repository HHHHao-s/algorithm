#include "../s.h"


//00 
//01
//10
//11

class Solution {
private:
    vector<vector<long long>> f;
    int n ;

    void maintain(int index){
        auto &a  = f[index*2], &b = f[index*2+1];
        f[index][0] = max(a[1]+ b[0], a[0]+b[2]);
        f[index][1] = max(a[0]+ b[3], a[1]+b[1]);
        f[index][2] = max(a[3]+b[0], a[2]+b[2]);
        f[index][3] = max(a[3]+b[1], a[2]+b[3]); 

    }

    void build(vector<int>& nums , int index, int l, int r){

        if(l==r){
            f[index][3] = max(0, nums[l]);
            return;
        }
        int m = (l+r)/2;
        build(nums, index*2 , l, m);
        build(nums, index*2+ 1, m+1, r);
        maintain(index);

    }

    void update(int index, int l, int r, int i, int x){

        if(l==r){
            f[index][3] = max(0, x);
            return;
        }

        int m = (l+r)/2;

        if(i<=m){
            update(index * 2, l, m, i, x);
        }else{
            update(index *2+1, m+1, r, i ,x);
        }
        maintain(index);
    }



public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
    
        f.assign(2 << (32 - __builtin_clz(n)), vector<long long>(4));


        build(nums, 1, 0, n-1);
        long long ans = 0;
        for(auto q: queries){
            update(1, 0, n-1, q[0], q[1]);
            ans = ans + f[1][3];


        }

        return ans  % 1'000'000'007;
    }
};