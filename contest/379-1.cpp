#include "../s.h"

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {

        int mx =0;

        int mx_size=0;
        for(int i=0;i<dimensions.size();i++){
            auto &rec = dimensions[i];
            if(mx < rec[0]*rec[0]+rec[1]*rec[1]){
                mx = rec[0]*rec[0]+rec[1]*rec[1];

                mx_size =  rec[0]*rec[1];
            }else if(mx==rec[0]*rec[0]+rec[1]*rec[1]){
                mx_size = max(mx_size, rec[0]*rec[1]);
            }
        }
        return mx_size;

    }
};