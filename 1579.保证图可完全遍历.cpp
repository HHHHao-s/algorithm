#include "s.h"
/*
 * @lc app=leetcode.cn id=1579 lang=cpp
 *
 * [1579] 保证图可完全遍历
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
private:
    UnionFind alice, bob;
    int cnt{0};

    void build(int type, vector<vector<int>>& edges){
        for(auto &edge:edges){
            if(edge[0]!=type){
                continue;
            }
            if(type==3 ){
                if(alice.Find(edge[1])!=alice.Find(edge[2])){
                    alice.Union(edge[1],edge[2]);
                    cnt++;
                }
                if(bob.Find(edge[1])!=bob.Find(edge[2])){
                    bob.Union(edge[1],edge[2]);
                }
            }
            else if( type==2){
                if(bob.Find(edge[1])!=bob.Find(edge[2])){
                    bob.Union(edge[1],edge[2]);
                    cnt++;
                }
            }else if(type==1){
                if(alice.Find(edge[1])!=alice.Find(edge[2])){
                    alice.Union(edge[1],edge[2]);
                    cnt++;
                }
            }
            
        }
    }

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        alice=UnionFind(n+1);
        bob = UnionFind(n+1);

        build(3, edges);
        build(1, edges);
        build(2,edges);

        if(alice.region!=2 || bob.region!=2){
            return -1;
        }
        return edges.size()-cnt;

    }
};
// @lc code=end

