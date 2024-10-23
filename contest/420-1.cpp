#include "../s.h"


class Solution {
public:
    vector<string> stringSequence(string target) {
        
        
        vector<string> ans;
        string cur;
        for(char c: target){

            cur+='a';
            ans.push_back(cur);
            while(cur.back()!=c){
                cur.back()++;
                ans.push_back(cur);
            }


        }

        return ans;

    }
};