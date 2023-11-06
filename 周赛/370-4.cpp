#include "../s.h"

// 树状数组: 动态维护前缀和
class BIT{
private:
    vector<long long> c;
public:
    BIT(int n){
        c = vector<long long>(n+1, INT_MIN);
    }
    BIT(set<long long> s){
        c.push_back(INT_MIN);
        long long ma = INT_MIN;
        for(auto x:s){
            ma = max(ma, x);
            c.push_back(ma);
        }
    }
    
    void update(int i, long long z){
        for(;i>0&&i<c.size();i+=(-i)&i){
            c[i] = max(c[i],z);
        }
    }

    long long pre_max(int i){
        long long s=INT_MIN;
        for(;i>0&&i<c.size();i-=(-i)&i){
            s = max(s, c[i]);
        }
        return s;
    }
};
class Solution {


public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            int x = nums[i]-i;
            s.insert(x);
        }
        unordered_map<int,int> s2index;
        int index = 1;
        for(auto x:s){
            s2index[x]=index++;
        }
        BIT b(s.size());
        long long ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            index = s2index[nums[i]-i];
            long long new_w = max(b.pre_max(index),0ll) +nums[i];
            ans = max(new_w,ans);
            b.update(index, new_w);
        }
        return ans;

    }
};

int main(){
    Solution s;

    vector<int> nums={3,3,5,6};
    cout << s.maxBalancedSubsequenceSum(nums);

}