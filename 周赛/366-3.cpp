#include "../s.h"

class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        if(s1==s2) return 0;
        int n =s1.size();
        int zero1=0,zero2=0;
        vector<int> pos;
        for(int i=0;i<n;i++){
            if(s1[i]=='0'){
                zero1++;
            }
            if(s2[i]=='0'){
                zero2++;
            }
            if(s1[i]!=s2[i]){
                pos.push_back(i);
            }
        }
        if((abs(zero1-zero2)&1)==1){
            return -1;
        }

        int f0=0, f1=x;
        for(int i=1;i<pos.size();i++){
            int tmp = f1;
            f1 = min(f1 + x, f0+(pos[i]-pos[i-1])*2);
            f0 = tmp;
        }

        return f1/2;


    }
};

int main(){
    Solution s;

    cout << s.minOperations("11001011111",
"01111000110",
2);

    return 0;
}