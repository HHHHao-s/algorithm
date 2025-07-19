#include "s.h"

class Solution {
public:
    int n;
    vector<int> splitIntoFibonacci(string num) {
  
        n = num.size();
        vector<int> a;
        
        int nret = 0;
        for(int i=1;i<n;i++){
            string temp;
            long long  th = stoll(num.substr(0, i));
            if(i>1 && num[0]=='0'){
                break;
            }
            if(th>(1ll<<31)){
                return {};
            }
            temp += num.substr(0, i);
            a.push_back(th);
            auto temp_tmp = temp;
            for(int j=1;j<n-i;j++){
                if(j>1&&num[i]=='0'){
                    break;
                }
                long long th2= stoll(num.substr(i,j));
                if(th2>(1ll<<31)){
                    break;
                }

                temp+= num.substr(i,j);
                a.push_back(th2);
                long long t1=th, t2= th2, t3= 0;
                while(1){
                    t3 = t1+ t2;
                    if(t3>(1ll<<31)){
                        break;
                    }
                    string num3 = to_string(t3);
                    
                    temp+=num3;
                    a.push_back(t3);
                    if(temp.size()>=num.size()){
                        break;
                    }
                    t1 = t2;
                    t2 = t3;
                }
                if(temp==num){
                    return a;
                }
                a.resize(1);
                temp = temp_tmp;
                
            }
            a.clear();

        }

        return {};


    }



};

int main(){

    Solution s;
    printArr( s.splitIntoFibonacci("3611537383985343591834441270352104793375145479938855071433500231900737525076071514982402115895535257195564161509167334647108949738176284385285234123461518508746752631120827113919550237703163294909"));
    printArr( s.splitIntoFibonacci("11235813"));
    
    printArr( s.splitIntoFibonacci("112358130"));
}