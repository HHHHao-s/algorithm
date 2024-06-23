#include "../s.h"

class Solution {
public:
    int m;
    int n;

    int arr[31][31][31][31];

    int f(int u, int d ,int l, int r , vector<vector<int>>& grid){
        if(arr[u][d][l][r] !=-1){
            return arr[u][d][l][r];
        }
        int ml=n, mu=m, mr = 0, md = 0;

        for(int i=u;i<d;i++){
            for(int j=l;j<r;j++){
                if(grid[i][j]==0){
                    continue;
                }
                ml = min(ml, j);
                mu = min(mu, i);
                mr = max(mr, j);
                md = max(md, i);
            }
        }
        arr[u][d][l][r] = (mr-ml+1) * (md-mu+1);
        return (mr-ml+1) * (md-mu+1);
    }


    int f2(int u, int d ,int l, int r , vector<vector<int>>& grid){
        int ans = 10000000000;
        for(int k=l;k<r;k++){
            ans = min(ans, f(u, d, l, k,grid) + f(u, d, k ,r, grid));
            
        }
        for(int k=u;k<d;k++){
            ans = min(ans, f(u, k, l, r,grid)+ f(k,d,l,r,grid));
        }

        return ans;
        

    }

    int f1(int x ,int y,vector<vector<int>>& grid){

        int a = min(f(0, x, 0, n, grid) + f2(x, m, 0, n, grid), f2(0, x, 0, n, grid) + f(x, m, 0, n, grid));

        int b = min(f(0, m, 0, y, grid)+ f2(0,m, y,n,grid),f2(0, m, 0, y, grid)+ f(0,m, y,n,grid));


        return min(a,b);

    }
    int minimumSum(vector<vector<int>>& grid) {
        std::fill(&arr[0][0][0][0], &arr[0][0][0][0] + sizeof(arr)/sizeof(arr[0][0][0][0]), -1);
        m=  grid.size();
        n= grid[0].size();
        int ans = 10000000000;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                ans = min(ans, f1(i, j, grid));
            }
        }

        return ans;



    }
};
