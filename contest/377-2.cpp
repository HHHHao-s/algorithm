#include "../s.h"

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        
        unordered_set<int> hgap, vgap;
        
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        hgap.insert(m-1);
        for(int h:hFences){
            hgap.insert(abs(h-1));
            hgap.insert(abs(m-h));
            for(int h2:hFences){
                hgap.insert(abs(h2-h));
            }
        }
        vgap.insert(n-1);
        for(int v:vFences){
            vgap.insert(abs(v-1));
            vgap.insert(abs(n-v));
            for(int v2:vFences){
                vgap.insert(abs(v2-v));
            }
        }
        long long ans = 0 ;
        for(int can: hgap){
            if(vgap.count(can)){
                ans = max(ans,(long long)can*(long long)can);
            }
        }
        if(ans ==0){
            return -1;
        }
        return (int)(ans%(1000000007));


    }
};