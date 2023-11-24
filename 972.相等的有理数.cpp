#include "s.h"
/*
 * @lc app=leetcode.cn id=972 lang=cpp
 *
 * [972] 相等的有理数
 */

// @lc code=start
class Solution {
private:
    void shrink(string &inte, string &nonrep, string &rep){
        
        

        if(rep.size()==0){
            int i=nonrep.size()-1;
            for(;i>=0;i--){
                if(nonrep[i]!='0'){
                    break;
                }
            }
            nonrep.resize(i+1);
            return;
        }else if(rep.size()==1){
            
            int i=nonrep.size()-1;
            for(;i>=0;i--){
                if(nonrep[i]==rep[0]){
                    continue;
                }
                break;
            }
            nonrep.resize(i+1);
        }else if(rep.size()==2){
            if(rep[0]==rep[1]){
                rep.resize(1);
                
                int i=nonrep.size()-1;
                for(;i>=0;i--){
                    if(nonrep[i]==rep[0]){
                        continue;
                    }
                    break;
                }
                nonrep.resize(i+1);
            }else{
                
                int i = nonrep.size()-1;
                
                while(i>=0 && rep[1]==nonrep[i]){
                    swap(rep[0],rep[1]);
                    i--;
                }
                nonrep.resize(i+1);
            }
            
        }else if(rep.size()==3){
            if(rep[0]==rep[1] && rep[1]==rep[2]){
                rep.resize(1);
                
                int i=nonrep.size()-1;
                for(;i>=0;i--){
                    if(nonrep[i]==rep[0]){
                        continue;
                    }
                    break;
                }
                nonrep.resize(i+1);
            }else{
                int i = nonrep.size()-1;
                
                while(i>=0 && rep[2]==nonrep[i]){
                    swap(rep[1],rep[2]);
                    swap(rep[0],rep[1]);
                    i--;
                }
                nonrep.resize(i+1);
            }
        }else{
            if(rep[0]==rep[1]&& rep[2]==rep[3] && rep[1]==rep[2]){
                rep.resize(1);
                
                int i=nonrep.size()-1;
                for(;i>=0;i--){
                    if(nonrep[i]==rep[0]){
                        continue;
                    }
                    break;
                }
                nonrep.resize(i+1);
            }else if(rep[0]==rep[2] && rep[1]==rep[3]){
                rep.resize(2);
                int i = nonrep.size()-1;
                
                while(i>=0 && rep[1]==nonrep[i]){
                    swap(rep[0],rep[1]);
                    i--;
                }
                nonrep.resize(i+1);
            }else{
                int i = nonrep.size()-1;
                
                while(i>=0 && rep[2]==nonrep[i]){
                    swap(rep[3],rep[2]);
                    swap(rep[1],rep[2]);
                    swap(rep[0],rep[1]);
                    i--;
                }
                nonrep.resize(i+1);
            }
        }

        if(rep.size()==1 && rep[0]=='9'){
            rep.clear();
            if(nonrep.size()!=0){
                nonrep[nonrep.size()-1]++;
                
            }else{
                int t = stoi(inte)+1;
                inte= to_string(t);
            }
        }
        if(rep.size()==1 && rep[0]=='0'){
            rep.clear();
        }

    }

public:
    bool isRationalEqual(string s, string t) {
        size_t sdot_pos = s.find('.');
        size_t tdot_pos = t.find('.');
        
        
        int slc = s.find('(');
        int tlc = t.find('(');
        string s1,s2,s3;
        if(sdot_pos!=string::npos){
            s1 = s.substr(0,sdot_pos);
            if(slc!=string::npos){
                s2 = s.substr(sdot_pos+1, slc-sdot_pos-1);
                s3 = s.substr(slc+1, s.size()-slc-2);
            }else{
                s2 = s.substr(sdot_pos+1, s.size()-sdot_pos-1);
            }
        }else{
            s1 = s;
        }
        
        string t1,t2,t3;
        if(tdot_pos!=string::npos){
            t1 = t.substr(0, tdot_pos);
            if(tlc!=string::npos){
                t2 = t.substr(tdot_pos+1, tlc-tdot_pos-1);
                t3 = t.substr(tlc+1, t.size()-tlc-2);
            }else{
                t2 = t.substr(tdot_pos+1, t.size()-tdot_pos-1);
            }
        }else{
            t1 = t;
        } 

        

        shrink(s1, s2, s3);
        shrink(t1, t2, t3);
    
        return s1==t1 && s2==t2 && s3==t3;
    
        
    }
};
// @lc code=end

int main(){

    Solution s;

    cout << s.isRationalEqual("0.(36)", "0.(3636)");
}