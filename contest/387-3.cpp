#include "../s.h"

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        
        int n = grid.size();

        int ys[3]={0,0,0};
        int ywhole  =0;
        int xs[3] ={0,0,0};
        int xwhole = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i<n/2 && j<n/2 && i-j==0) || (i<n/2 && j> n/2 && i+j == n-1)||(j==n/2 && i>=n/2) ){

                    ys[grid[i][j]]++;
                    ywhole++;
                }else{
                    xs[grid[i][j]]++;
                    xwhole++;
                }
            }

        }
        int ans= INT_MAX;
        for(int i=0;i<=2;i++){
            for(int j=0;j<=2;j++){
                if(i!=j){
                    ans = min(ans, ywhole- ys[i]+xwhole-xs[j]);
                }
            }
        }
        return ans;


    }
};

int main(){
    Solution s;
    vector<vector<int>> g = {{1,2,2},{1,1,0},{0,1,0}};
    cout << s.minimumOperationsToWriteY(g);
}