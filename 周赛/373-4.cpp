#include "../s.h"
class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        
        vector<int> prefix;
        unordered_set<char> yuan={'a','e','i','o','u'};
        int n =s.size();
        vector<int> len;
        for(int j=1;j<n;j++){
            if((j*j)%k==0){
                len.push_back(2*j);
            }
        }
        int cur=0;
        for(int i=0;i<s.size();i++){
            if(yuan.count(s[i])){
                cur++;
            }else{
                cur--;
            }
            prefix[i]=cur;
        }

    }
};