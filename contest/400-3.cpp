#include "../s.h"

class Solution {
public:
    string clearStars(string s) {
        
        int last = 0;
        char mn = 'z'+1;

        
        priority_queue<pair<char,int>, vector<pair<char,int>> , greater<pair<char,int>>> pq;
        vector<bool> deleted(s.size());

        for(int i =0;i<s.size();i++){
            
            char c = s[i];
            if(c=='*'){
                auto [ch, mlast] = pq.top();
                pq.pop();
                deleted[i] = 1;
                deleted[-mlast] = 1;
            }else{
                
                pq.push({c, -i});
            }
            

        }

        string ret;

        for(int i =0;i<s.size();i++){
            if(!deleted[i]){
                ret.push_back(s[i]);
            }
        }
        return ret;
    }
};