#include "s.h"

int main(){
    for(int j=0;j<(1<<5);j++){
        cout << j << "的子集是:" << endl;
        for(int x=j;x;x=(x-1)&j){ // 求子集
            cout << x << ' ';
        }
        cout << endl;
    
    }
    

    return 0;
}