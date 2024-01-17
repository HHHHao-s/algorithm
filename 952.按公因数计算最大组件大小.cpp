#include "s.h"
/*
 * @lc app=leetcode.cn id=952 lang=cpp
 *
 * [952] 按公因数计算最大组件大小
 */

// @lc code=start
struct UnionFind{
    UnionFind() = default;

    UnionFind(size_t n): arr(n){
        for(int i=0;i<n;i++){
            arr[i] = {i,1};
        }
        region = n;
    }

    int Find(int x){
        return arr[x].fa==x?x:(arr[x].fa=Find(arr[x].fa));
    }
    void Union(int x, int y){
        int fax = Find(x);
        int fay = Find(y);
        if(fax!=fay){
            if(arr[fax].cnt<arr[fay].cnt){
                swap(fax, fay);
            }
            // 把fay合并到fax
            arr[fax].cnt += arr[fay].cnt;
            arr[fay].fa = fax;
            region--;
        }
    }
    int& GetCnt(int x){
        return arr[Find(x)].cnt;
    }

    struct Info{
        int fa,cnt;
    };
    vector<Info>  arr;
    int region{0};
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        unordered_set<int> exist;
        for(int num: nums){
            exist.insert(num);
        }
        vector<bool> primes(100000,1); 
        UnionFind uf(100001);
        for(int i=2;i<=100000;i++){
            if(primes[i]==0){
                continue;
            }
            int fa = -1;
            for(int j=i;j<=100000;j+=i){
                primes[j]=0;
                if(exist.count(j)){
                    if(fa==-1){
                        fa=j;
                    }else{
                        uf.Union(fa, j);
                    }
                    
                }
            }
        }
        int ans = 0;
        for(int i=2;i<=100000;i++){
            if(uf.arr[i].fa==i){
                ans = max(ans, uf.arr[i].cnt);
            }
            
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums = {4,6,15,35};
    cout <<s.largestComponentSize(nums);
}