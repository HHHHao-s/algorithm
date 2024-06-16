#include "../s.h"

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        
        int t = x;
        int sum = 0;
        while(x){
            sum+= x%10;
            x/=10;
        }
        if( t%sum==0){
            return sum;
        }
        return -1;

    }
};



int main(){
    
}