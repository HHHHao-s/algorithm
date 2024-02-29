#include "s.h"
/*
 * @lc app=leetcode.cn id=2076 lang=cpp
 *
 * [2076] 处理含限制条件的好友请求
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
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        
        vector<bool>ans;
        UnionFind uf(n);
        for(auto &request: requests){

            auto tmp = uf;
            uf.Union(request[0], request[1]);
            bool can = true;
            for(auto &res: restrictions){
                if(uf.Find(res[0])==uf.Find(res[1])){
                    can = false;
                    uf = tmp;
                    break;
                }
            }
            ans.push_back(can);
            

        }
        return ans;

    }
};
// @lc code=end

