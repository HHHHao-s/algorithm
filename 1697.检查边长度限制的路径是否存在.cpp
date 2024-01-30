#include "s.h"
/*
 * @lc app=leetcode.cn id=1697 lang=cpp
 *
 * [1697] 检查边长度限制的路径是否存在
 */

// @lc code=start
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {

        vector<bool> ans(queries.size(), 1);
        map<int, vector<pair<int,int>>> edgeVetex;
        for(auto &edge:edgeList){
            edgeVetex[edge[2]].push_back({edge[0],edge[1]});
        }

        UnionFind uf(n);
        struct info{
            int u,v,index;
        };
        map<int ,vector<info>> offQ;
        for(int i=0;i<queries.size();i++){
            auto &q = queries[i];
            offQ[q[2]].push_back({q[0], q[1], i});
        }
        
        for(auto &[len, nodes]: edgeVetex){
            while(!offQ.empty() && offQ.begin()->first<=len){
                for(auto [u,v,index]: offQ.begin()->second){
                    if(uf.Find(u) == uf.Find(v)){
                        ans[index] = true;
                    }else{
                        ans[index] = false;
                    }
                }
                offQ.erase(offQ.begin()->first);
            }
            for(auto [n1, n2]: nodes){
                uf.Union(n1, n2);
            }
            
        }
        while(!offQ.empty()){
            for(auto [u,v,index]: offQ.begin()->second){
                if(uf.Find(u) == uf.Find(v)){
                    ans[index] = true;
                }else{
                    ans[index] = false;
                }
            }
            offQ.erase(offQ.begin()->first);
        }

        return ans;

    }
};
// @lc code=end

