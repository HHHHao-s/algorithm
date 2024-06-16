#include "../s.h"

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int ones=0;
        string ans="";

        for(int l=0,r=0;r<n;r++){
            if(s[r]=='1'){
                ones++;
            }
            while(ones>k){
                if(s[l]=='1'){
                    ones--;
                }
                l++;
            }
            while(s[l]=='0'&&l<r){
                l++;
            }
            
            if(ones==k){
                
                string sub = s.substr(l, r-l+1);
                if(ans==""){
                    ans = sub;
                }else{
                    if(ans.size()>sub.size()){
                        ans = sub;
                    }else if(ans.size()<sub.size()){
                        continue;
                    }else{
                        if(strcmp(sub.c_str(), ans.c_str())>0){
                            ans = sub;
                        }
                    }
                }
                    
                
            }
            
        }
        return ans;

    }
};