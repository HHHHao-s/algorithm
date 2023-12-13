#include "s.h"
/*
 * @lc app=leetcode.cn id=2709 lang=cpp
 *
 * [2709] 最大公约数遍历
 */

// @lc code=start
struct UnionFind{
    UnionFind(size_t n): arr(n){
        for(int i=0;i<n;i++){
            arr[i] = {i,1};
        }
    }

    int Find(int x){
        return arr[x].fa==x?x:(arr[x].fa=Find(arr[x].fa));
    }
    void Union(int x, int y){
        int fax = Find(x);
        int fay = Find(y);
        if(fax!=fay){
            arr[fax].cnt += arr[fay].cnt;
            arr[fay].fa = fax;
        }
    }
    int& GetCnt(int x){
        return arr[Find(x)].cnt;
    }
    

    struct Info{
        int fa,cnt;
    };
    vector<Info>  arr;
};

class Solution {
private:
    
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        if(nums[0]==1 && nums.size()>1){
            return false;
        }

        int n =unique(nums.begin(),nums.end()) - nums.begin();
        int mx = *max_element(nums.begin(), nums.end());
        
        vector<int> mp(mx+1, -1);
        for(int i=0;i<n;i++){
            
            mp[nums[i]] = i;
        }
        vector<bool> primes(mx+1,1);
        UnionFind uf(n);
        for(int i=2;i<=mx;i++){
            if(primes[i]){
                int last=-1;
                for(int j=i;j<=mx;j+=i){
                    if(mp[j]!=-1){
                        if(last!=-1){
                            uf.Union(last, mp[j]);
                        }else{
                            last = mp[j];
                        }
                    }
                    primes[j]=false;
                }
                
            }
        }
        
        
        return uf.GetCnt(0)==n;

    }   
};
// @lc code=end

int main(){
    Solution s;
    vector<int> ves={
        4,3,12,8
    };
    cout << s.canTraverseAllPairs(ves);
}