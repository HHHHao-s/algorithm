#include "../s.h"

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans = 0;
        vector<int> have(target+1);
        int high=0;
        for(int i=0;i<coins.size();i++){
            have[coins[i]]++;

        }
        
        for(int i=1;i<=target;i++){

            if(have[i]==0&&i>high){
                ans++;
                high = high+i;

            }else{
                high = max(high, high+have[i]*i);
            }
            
            
            
            if(high>=target){
                break;
            }
        }

        return ans;
    }
};

int main(){

    Solution s;
    vector<int> coins = {5,6,7};
    cout << s.minimumAddedCoins(coins, 15);
}