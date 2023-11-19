#include "../s.h"

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {

        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        int j = -1;
        for(int i=0;i<min({n1,n2,n3});i++){
            if(s1[i]==s2[i] && s2[i]==s3[i]){
                j=i;

            }else{
                break;
            }
        }
        if(n1==n2 && n2==n3 && j==n1-1){
            return 0;
        }
        if(s1[0]!=s2[0] || s1[0]!=s2[0] || s2[0]!=s3[0]){
            return -1;
        }
        return n1-j+n2-j+n3-j-3;

    }
};