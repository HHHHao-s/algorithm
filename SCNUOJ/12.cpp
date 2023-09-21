#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    char c;
    char ans[5]={0};
    int top=0;
    while((c=getchar())=='6' || c=='9'){
        ans[top++]=c;
    }

    for(int i=0;i<top;i++){
        if(ans[i]=='6'){
            ans[i]='9';
            break;
        }
    }
    

    

    printf("%s", ans);


    return 0;
}