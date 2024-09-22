#include "../s.h"



class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        
        int co=0;
        unordered_set<string> s;

        for(auto &st: bannedWords){
            s.insert(st);
        }
        for(auto &mes: message){
            if(s.count(mes)){
                co++;
            }
            if(co>=2){
                return true;
            }
        }
        return false;

    }
};