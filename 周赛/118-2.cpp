#include "../s.h"

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        
        // vector<int> hline;
        // vector<int> vline;
        // unordered_set<int> hbar,vbar;
        if(vBars.size()==0 || hBars.size()==0){
            return 1;
        }
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        int con_h=0;
        int tmp_con=1;
        int last = hBars[0];
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]==hBars[i-1]+1){
                tmp_con++;

            }else{
                
                con_h=max(con_h, tmp_con);
                tmp_con=1;
            }
        }
        
        con_h=max(con_h, tmp_con);

        
        
        int con_v=0;
        tmp_con=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]==vBars[i-1]+1){
                tmp_con++;
            }else{
                
                con_v=max(con_v, tmp_con);
                tmp_con=1;
            }
        }
        
        con_v=max(con_v, tmp_con);

        
        


        return max(1, (min(con_v, con_h)+1)*(min(con_v, con_h)+1));


    }
};

int main(){
    Solution s;
    vector<int> hBars={};
    vector<int> vBars={};
    cout << s.maximizeSquareHoleArea(2,3,hBars, vBars);
}
