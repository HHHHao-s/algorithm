#include "../s.h"

class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        
        vector<int >ans(n);
        if(x>y){
            swap(x,y);
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }
                int ti = min(i,j);
                int tj = max(i,j);
                
                
                
                ans[(min(abs(ti-tj), abs(x-ti)+abs(tj-y)+1))-1]++;
            }
        }
        return ans;

    }
};