#include "s.h"

class Solution {
public:
    string baseNeg2(int n) {
        if(n==0){
            return "0";
        }
        long long copy = n;
        int digit=0;
        while(copy&(-1<<digit)){
            if(digit%2==1 && copy&(1<<digit)){
                // 指针指到这里，假设它已经减去了，为了保持原样，就要加回来两倍的这个数
                // 接着继续表示加完之后的数
                copy+=1<<(digit+1);
            }

            digit++;

        }
        digit--;
        string s;
        while(digit>=0){
            if((1<<digit)&copy){
                s.push_back('1');
            }else{
                s.push_back('0');
            }
            digit--;
        }

        return s;
    

    }
};

int main(){


    Solution s;

    cout << s.baseNeg2(1000000000);

    return 0;
}