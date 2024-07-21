#include "../s.h"

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        
        long long ans= 0;

        vector<int> diff;
        int n = nums.size();
        for(int i=0;i<n;i++){
            diff.push_back(target[i]-nums[i]);
        }

        

        for(int j=0;j<n;j++){
            int begin = diff[j];
            if(begin ==0){
                continue;
            }
            int k=j;
            int m = begin;
            if(begin<0){
                while(k<n && diff[k]<0){
                    k++;
                }
            }else{
                while(k<n && diff[k]>0){
                    k++;
                }
            }
            // [j,k)
            deque<int> q;
            if(begin>0){
                q.push_back(0);
                for(int i=j;i<k;i++){
                    int c = 0;
                    while(q.size()>0 && diff[i]<=q.back()){
                        q.pop_back();
                        c=1;
                    }
                    if(!c){
                        ans += diff[i] - q.back();
                    }
                    q.push_back(diff[i]);
                    
                }
            }else{
                q.push_back(0);
                for(int i=j;i<k;i++){
                    int c = 0;
                    diff[i] = -diff[i];
                    while(q.size()>0 && diff[i]<=q.back()){
                        q.pop_back();
                        c=1;
                    }
                    if(!c){
                        ans += diff[i] - q.back();
                    }
                    q.push_back(diff[i]);
                    
                }
            }
            j=k-1;
            
            
        }
        return ans;


    }
};