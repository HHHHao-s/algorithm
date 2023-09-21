#include <vector>
#include <iostream>
#include <bitset>

using namespace std;



int main(){

    vector<int> pos; // 种了花的地方
    int s=0;
    int a;
    int n=0;
    while(cin>>a){
        if(a==1){
            pos.push_back(s);
        }
        s++;      
        n = a; 
    }
    
    s--;
    if(pos.empty()){
        if((s+1)/2>=a){
            cout << "true";
        }else{
            cout << "false";
        }       
        return 0;
    }

    if(pos.back()==s){ // 最后一个是n
        pos.pop_back();   
    }
    int has=0;

    if(pos[0]!=0 && pos[0]>=2){// 第一个位置没有花
        int next = pos[0];

        has += next/2; 
    }

    for(int i=1;i<pos.size();i++){
        int left = pos[i-1];
        int right = pos[i];
        if(right-left<=3){
            continue;
        }
        
        has += (right-2-left)/2;
        if(has>=n){
            cout << "true";
            return 0;
        }
    }

    if(pos.back()!=s-1 && s-pos.back()-1>=2){// 最后一个不是花，且没有判断过

        has+= (s-1-pos.back())/2;
    }

    if(has>=n){
        cout << "true";
    }else{
        cout << "false";
    }

    return 0;
}

