#include "../s.h"

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        
        int min_di = 0;
        long long ans=0;
        if(n>limit){
            if(n>3*limit){
                return 0;
            }else if(n==3*limit){
                return 1;
            }
            else if(n>2*limit){
                min_di = n-2*limit;
                for(int i=min_di;i<=limit && i<=n;i++){
                    int tmd = n-i;
                    if(tmd&1){
                        int mid = tmd/2;
                        ans += 2*min(mid+1, limit-mid);
                    }else{
                        ans ++;
                        int mid = tmd/2;
                        ans += 2*(min(mid, limit-mid));
                    }
                    

                }
                return ans;
            }else{
                min_di = 0;
                for(int i=min_di;i<=limit && i<=n;i++){
                    int tmd = n-i;
                    if(tmd&1){
                        int mid = tmd/2;
                        ans += 2*min(mid+1, limit-mid);
                    }else{
                        ans ++;
                        int mid = tmd/2;
                        ans += 2*(min(mid, limit-mid));
                    }
                
                }
                return ans;
            }
            
        }else{
            for(int i=0;i<=limit && i<=n;i++){
                int tmd = n-i;
                if(tmd&1){
                    int mid = tmd/2;
                    ans += 2*min(mid+1, limit-mid);
                }else{
                    ans ++;
                    int mid = tmd/2;
                    ans += 2*(min(mid, limit-mid));
                }
            }
            return ans;
        }   
    }
};
int main(){

    Solution s;
    cout <<s.distributeCandies(1,2);
    
}