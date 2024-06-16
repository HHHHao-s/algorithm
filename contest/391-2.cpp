#include "../s.h"

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int ans =0;
        int empty=0;
        int full = numBottles;
        while(full){
            ans+=full;
            empty+=full;
            full=0;
            
            while(numExchange<=empty){
                empty-=numExchange;
                numExchange++;
                full++;
            }
        }

        return ans;
        

    }
};



int main(){

}