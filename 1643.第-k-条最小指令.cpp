#include "s.h"
/*
 * @lc app=leetcode.cn id=1643 lang=cpp
 *
 * [1643] 第 K 条最小指令
 */

// @lc code=start
class Solution {
public:


    string kthSmallestPath(vector<int>& destination, int k) {
        vector<vector<long long>> c(31, vector<long long>(31));

        c[0][0] = 1;
        c[1][0] = 1;
        c[1][1] = 1;
        for(int i=2;i<=30;i++){
            c[i][0] = c[i][i] =1;
            for(int j=1;j<i;j++){

                c[i][j] = c[i-1][j] + c[i-1][j-1];

            }

        }


        int row = destination[0];
        int column = destination[1];

    
        long long l = 1;
        long long r = c[row+column][min(row, column)];
        int x= 0;
        int y= 0;
        string ret;
        while(l<r){
            int nx= x+1;
            int ny= y+1;
            if(nx<=row){
                long long rd = c[row-nx+column-y][min(row-nx, column-y)];
                if(r-rd>=k){
                    r-=rd;
                    y = ny;
                    ret.push_back('H');
                    continue;
                }
            }
            if(ny<=column){
                long long ld= c[row-x+ column-ny][min(row-x,column-ny )];
                if(l+ld<=k){
                    l+=ld;
                    x= nx;
                    ret.push_back('V');
                    continue;
                }
            }
        }
        if(x!=row){
            for(int i=x;i<row;i++){
                ret.push_back('V');
            }
        }
        if(y!=column){

            for(int i=y;i<column;i++){
                ret.push_back('H');
            }

        }
        return ret;

    }
};
// @lc code=end

int main(){

    Solution s;
    vector<int> des = {2,3};
    cout << s.kthSmallestPath(des, 3);
}