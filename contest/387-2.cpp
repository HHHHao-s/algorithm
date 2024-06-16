#include "../s.h"

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m =grid.size();
        int n = grid[0].size();


        vector<vector<long long>> presum(m ,vector<long long>(n));
        presum[0][0] = grid[0][0];
        int ans = 0;
        if(presum[0][0]<=k){
            ans++;
        }
        for(int i=1;i<n;i++){
            presum[0][i] = presum[0][i-1] + grid[0][i];
            if(presum[0][i]<=k){
                ans++;
            }
        }
        for(int i=1;i<m;i++){
            presum[i][0] = presum[i-1][0]+ grid[i][0];
            if(presum[i][0]<=k){
                ans++;
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                presum[i][j] = presum[i][j-1] + presum[i-1][j] - presum[i-1][j-1] + grid[i][j];
                if(presum[i][j]<=k){
                    ans ++;
                }
            }
        }
        return ans;


    }
};


int main(){
    Solution s;
    vector<vector<int>> g={
        {7,2,9},
        {1,5,0},
        {2,6,6}
    };
    cout << s.countSubmatrices(g,20);
}