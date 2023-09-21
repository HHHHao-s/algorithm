#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {

        if(n==2){
            return 1;
        }else if(n==3){
            return 2;
        }else if(n==4){
            return 4;
        }else{

            int y = n%3;
            if(y==0){
                return pow(3, n/3);
            }else if(y==1){
                return pow(3, n/3-1)*4;
            }else if(y==2){
                return pow(3, n/3)*2;
            }

        }
        return 1;
    }   
};


int main(){

    Solution s;
    int n;
    cin >> n;

    cout << s.integerBreak(n);

    return 0;
}