#include "s.h"
/*
 * @lc app=leetcode.cn id=1240 lang=cpp
 *
 * [1240] 铺瓷砖
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> grid;
    int n ,m;
    int ans;

    void fill(int x, int y ,int len){
        for(int i=x;i<x+len;i++){
            for(int j=y;j<y+len;j++){
                grid[i][j] = 1;
            }
        }
    }

    void erase(int x, int y ,int len){
        for(int i=x;i<x+len;i++){
            for(int j=y;j<y+len;j++){
                grid[i][j] = 0;
            }
        }
    }

    void dfs(int x, int y, int cnt){
        bool full=1;
        if(cnt>=ans){
            return;
        }
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) {
                    full=0;
                    break;
                }
            }
            if(!full){
                break;
            }
        }
        if(full){
            ans = min(ans, cnt);
        }
        int ans = INT_MAX;
        int si=0,sj=0;
        for(int i=0;i<n;i++){
            bool found = 0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    si=i;
                    sj=j;
                    found=1;
                    break;
                }

            }
            if(found){
                break;
            }
        }

        for(int l=1;l<=min(n-si,m-sj);l++){                  
            bool can=1;
            for(int i1=si;i1<l+si;i1++){
                for(int j1= sj;j1<l+sj;j1++){
                    if(grid[i1][j1]==1){
                        can=0;
                        break;
                    }
                }
                if(can==0){
                    break;
                }
            }
            if(can){
                fill(si, sj, l);
                dfs(si,sj, cnt+1);
                erase(si, sj ,l);
            }
               
        }
        
        

    }

public:
    int tilingRectangle(int _n, int _m) {
        n = _n;
        m = _m;
        ans = max(n,m);
        grid = vector<vector<int>>(_n, vector<int>(_m));
        dfs(0,0, 0);
        return ans;
    }
};
// @lc code=end

int main(){

    Solution s;
    cout << s.tilingRectangle(11,13);
}