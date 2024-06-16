#include "../s.h"

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    indegree[j]++;
                }
            }
            
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                if(ans!=-1){
                    return -1;
                }
                ans = i;
                
            }
        }
        return ans;
    }
};

