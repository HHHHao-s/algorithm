#include "s.h"
/*
 * @lc app=leetcode.cn id=2867 lang=cpp
 *
 * [2867] 统计树中的合法路径数目
 */

// @lc code=start

vector<int> isPrime(100001, 1);

int init = [](){
    isPrime[1] = 0;

    for(int i=2;i<1000;i++){
        for(int j=i*i;j<100001;j+=i){
            isPrime[j] = 0;
        }
    }

    return 1;
}();

struct UnionFind{
    UnionFind() = delete;

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
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<int>> grid(n+1);
        for(auto &edge: edges){
            grid[edge[0]].push_back(edge[1]);
            grid[edge[1]].push_back(edge[0]);
        }
        UnionFind uf(n+1);
        vector<int> seen(n+1);
        function<void(int , int)> dfs=[&](int node, int far){
            if(seen[node]){
                return;
            }
            seen[node]  =1;
            for(int next: grid[node]){
                if(next!=far && !isPrime[next]){
                    uf.Union(next, node);
                    dfs(next, node);
                }
            }
            

        };
        long long ans = 0;
        for(int i=1;i<=n;i++){
            if(!isPrime[i]){
                continue;
            }
            long long cur = 0;

            for(int j: grid[i]){
                if(isPrime[j]){
                    continue;
                }
                if(!seen[j]){
                    dfs(j, -1);
                }
                long long cnt = uf.GetCnt(j);
                ans += cur * cnt;
                cur+=cnt;

            }
            ans += cur;

        }
        return ans;

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> edges= {
        {1,2},
        {1,3},
        {2,4},
        {2,5}
    };
    cout << s.countPaths(5, edges);
}