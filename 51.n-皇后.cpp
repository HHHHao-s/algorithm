#include "s.h"
/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:

    vector<int> cur; // 每一行queen所处位置
    
    int row=0,col=0,slash=0,slash2=0; // bitset

    vector<vector<string>> ret;
    int n;

    void take(int i, int j){

        col |= 1<<i;
        row |= 1<<j;
        slash |= 1<<(i+j);
        slash2 |= 1<<(n-j-1+i);

    }

    void unTake(int i, int j){

        col &= ~(1<<i);
        row &= ~(1<<j);
        slash &= ~(1<<(i+j));
        slash2 &= ~(1<<(n-j-1+i));
    }

    bool isTake(int i, int j){
        return (col&(1<<i)) || (row&(1<<j))|| (slash&(1<<(i+j))) || (slash2&(1<<(n-j-1+i)));
    }

    

    void dfs(int layer){
        

        if(layer==n){
            vector<string> ans;
            for(int i=0;i<n;i++){
                char str[10] =".........";
                str[cur[i]] = 'Q';
                str[n]=0;
                ans.emplace_back(str);
            }
            ret.emplace_back(std::move(ans));
            return;
        }

        for(int j=0;j<n;j++){
            if(!isTake(layer,j)){
                cur.push_back(j);
                take(layer,j);
                dfs(layer+1);
                unTake(layer,j);
                cur.pop_back();
            }
            
        }
    }


    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        dfs(0);
        return ret;

    }
};
// @lc code=end

int main(){

    Solution s;

    print2d(s.solveNQueens(4));

    return 0;
}