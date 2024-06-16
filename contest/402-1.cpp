#include "../s.h"




class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        
        unordered_map<int ,int> ct;

        for(int hour: hours){
            ct[hour%24]++;
        }

        int ans = 0;

        for(int i=0;i<=23;i++){
            for(int j=i;j<=23;j++){
                if(i==j){
                    if(((i+j)%24)==0)
                        ans += (ct[i]*(ct[i]-1))/2;
                }else{
                    if((i+j)%24==0){
                        ans += ct[i]*ct[j];
                    }
                }   
            }
        }
        return ans;
    }
};