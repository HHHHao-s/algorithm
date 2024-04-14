#include "../s.h"

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        vector<unordered_map<long long,int>> dp(17);
        for(int i=1;i<(1<<n);i++){
            // long long mul=1;
            long long g = -1;
            long long cur = 1;
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    cnt++;
                    cur*=coins[j];
                    if(g==-1){
                        g = coins[j];
                    }else{        
                        g = gcd(g, coins[j]);
                        cur = cur/g;
                        g = cur;
                    }
                    
                }
            }
            dp[cnt][cur]++;
        }
        
        long long l=1;
        long long r=50000001000;

        while(l<=r){

            long long mid = l+ (r-l)/2;
            long long cnt=0;
            long long flag = 1;
            for(int i=1;i<=n;i++){

                for(auto [each, ct]: dp[i]){
                    cnt = cnt+ mid/each*ct*flag;
                }
                
                flag*=-1;

            }
            if(cnt>=k){
                r=mid-1;
            }else{
                l=mid+1;
            }

        }
        return r+1;

    }
};
// 2 3 4 6 8 9 10 12 
int main(){
    vector<int> coins = {3,6,2,9};
    Solution s;
    cout << s.findKthSmallest(coins, 2);
    cout << s.findKthSmallest(coins, 3);
    cout << s.findKthSmallest(coins, 4);
    cout << s.findKthSmallest(coins, 5);
    cout << s.findKthSmallest(coins, 6);
    cout << s.findKthSmallest(coins, 7);
    cout << s.findKthSmallest(coins, 8);

}
