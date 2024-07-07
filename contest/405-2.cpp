#include "../s.h"


class Solution {
private:

    vector<string> f(int i ,int n, vector<string> &have){

        if(i==n){
            return have;
        }

        vector<string> next;

        for(auto &each:have){
            
            if(each.back()=='0'){
                next.push_back(each+'1');
            }else{
                next.push_back(each+'1');
                next.push_back(each+'0');
            }
        }
        return f(i+1, n, next);

    }

public:
    vector<string> validStrings(int n) {
        
        if(n==1){
            return {"0", "1"};
        }

        vector<string> tmp{"0", "1"};

        return f(1, n, tmp);

        

    }
};