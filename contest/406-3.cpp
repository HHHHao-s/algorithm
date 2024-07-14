#include "../s.h"

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        
        long long cost = 0;


        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end() ,greater<int>());

        long long v=1, h=1;


        int i=0,j=0;

        for(;i<m-1;i++){

            while(j<n-1 && verticalCut[j]> horizontalCut[i]){

                cost += h*verticalCut[j];
                v++;
                j++;

            }
            if(j==n-1 || (j<n-1 && verticalCut[j]<= horizontalCut[i])){
                cost += v*horizontalCut[i];
                h++;
            }

        }
        for(;j<n-1;j++){
            cost += h*verticalCut[j];
        }


        return cost;

    }
};