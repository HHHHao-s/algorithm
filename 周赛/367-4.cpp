#include "../s.h"

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        unsigned long long mul = 1;
        vector<vector<unsigned long long>> pre(m, vector<unsigned long long>(n,1)), suf(m, vector<unsigned long long>(n,1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pre[i][j] = mul;
                mul = (mul*(grid[i][j]%12345))%12345;
                
            }
        }
        mul=1;
        for(int i=m;i-->0;){
            for(int j=n;j-->0;){
                suf[i][j] = mul;
                mul = (mul*(grid[i][j]%12345))%12345;
            }
        }
        vector<vector<int>> ans(m, vector<int>(n,1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = (pre[i][j]*suf[i][j])%12345;
                
            }
        }
        return ans;
        

    }
};

int main(){
    Solution s;

    vector<vector<int>> mar={
        {1,2},
        {3,4}
    };

    print2d(s.constructProductMatrix(mar));
    return 0;
}