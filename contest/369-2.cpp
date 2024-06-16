#include "../s.h"


class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {

        long long sum1 =0;      
        long long sum2 =0;  
        long long zeros1=0;
        for(int x:nums1){
            if(x==0){
                zeros1++;
            }
            sum1+=x;

        }
        long long zeros2=0;
        for(int x:nums2){
            if(x==0){
                zeros2++;
            }
            sum2+=x;
        }
        if(sum1>sum2){
            long long diff = sum1-sum2;
            if(zeros2==0 || (zeros1==0 && diff<zeros2)){
                return -1;
            }else{
                return max(sum1+zeros1, sum2+zeros2);

            }

        }else if(sum2>sum1){
            int diff = sum2-sum1;
            if(zeros1==0 || (zeros2==0 && diff<zeros1)){
                return -1;
            }else{
                return max(sum1+zeros1, sum2+zeros2);
            }
        }else{
            if(zeros1==0 && zeros2==0){
                return sum1;
            }else if((zeros1 ==0 && zeros2!=0) || (zeros1!=0 && zeros2==0)){
                return -1;
            }else{
                return sum1+max(zeros1,zeros2);
            }
        }
        return -1;
        
    }
};