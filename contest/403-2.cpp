#include "../s.h"

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=  grid.size();
        int n = grid[0].size();
        int l=n, u=m, r = 0, d = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    continue;
                }
                l = min(l, j);
                u = min(i, u);
                r = max(r, j);
                d = max(d, i);
            }
        }

        return (r-l +1)* (d-u+1);

    }
};
