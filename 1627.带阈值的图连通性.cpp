#include "s.h"
/*
 * @lc app=leetcode.cn id=1627 lang=cpp
 *
 * [1627] 带阈值的图连通性
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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {

        UnionFind uf(n+1);
        
        if(threshold==0){
            vector<bool> ans(queries.size(), true);
            return ans;
        }
        for(int i=threshold+1;i<=n; i++){
            for(int j=i*2;j<=n;j+=i){
                uf.Union(i, j);
            }
        }
        vector<bool> ans;
        for(auto &query: queries){
            bool r = uf.Find(query[0])==uf.Find(query[1]);
            ans.push_back(r);
        }
        return ans;

    }
};
// @lc code=end

int main(){

    Solution s;
    vector<vector<int>> queries = {
        {6,12}
    };
    s.areConnected(14,4, queries);

}