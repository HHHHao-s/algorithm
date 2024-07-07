#include "../s.h"


class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
    
        vector<vector<int>> xs(m ,vector<int>(n)), ys(m, vector<int>(n));

        xs[0][0] = grid[0][0]=='X';
        ys[0][0] = grid[0][0]=='Y';


        int ret= 0;
        for(int i=1;i<m;i++){

            xs[i][0] = xs[i-1][0] + (grid[i][0]=='X'); 

            ys[i][0] = ys[i-1][0] + (grid[i][0] =='Y');

            if(xs[i][0] == ys[i][0] && xs[i][0]>0){
                    ret ++;
            }
        }

        for(int j=1;j<n;j++){
            xs[0][j] = xs[0][j-1] + (grid[0][j]=='X');
            ys[0][j] = ys[0][j-1] + (grid[0][j]=='Y');
            if(xs[0][j] == ys[0][j] && xs[0][j]>0){
                ret ++;
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                xs[i][j] = xs[i-1][j] + xs[i][j-1] - xs[i-1][j-1] + (grid[i][j]=='X');
                ys[i][j] = ys[i-1][j] + ys[i][j-1] - ys[i-1][j-1] + (grid[i][j]=='Y');
                if(xs[i][j] == ys[i][j] && xs[i][j]>0){
                    ret ++;
                }
            }


        }


        return ret;


    }
};