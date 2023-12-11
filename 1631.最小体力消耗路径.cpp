#include "s.h"
/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
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



public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n =heights[0].size();
        if(m==1 && n==1){
            return 0;
        }
        vector<pair<pair<int,int>,pair<int,int>>> edges;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i+1<m){
                    edges.push_back({{i,j},{i+1,j}});
                }
                if(j+1<n){
                    edges.push_back({{i,j},{i,j+1}});
                }
                
            }
        }

        auto cmp = [&](const pair<pair<int,int>,pair<int,int>> &a, const pair<pair<int,int>,pair<int,int>> &b){
            return abs(heights[a.first.first][a.first.second]-heights[a.second.first][a.second.second])<
                    abs(heights[b.first.first][b.first.second]-heights[b.second.first][b.second.second]);
        };

        sort(edges.begin(),edges.end(),cmp);

        UnionFind uf(m*n);

        int index=-1;
        auto f = [&](int x,int y){
            
            return x*n+y;
        };
        while(uf.Find(0)!=uf.Find(m*n-1)){
            index++;
            auto [a,b] = edges[index];
            
            uf.Union(f(a.first,a.second),f(b.first,b.second));

        }
        auto a = edges[index];
        return abs(heights[a.first.first][a.first.second]-heights[a.second.first][a.second.second]);

        

        

    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> heights={{4,3,4,10,5,5,9,2},{10,8,2,10,9,7,5,6},{5,8,10,10,10,7,4,2},{5,1,3,1,1,3,1,9},{6,4,10,6,10,9,4,6}};
    cout << s.minimumEffortPath(heights);
}