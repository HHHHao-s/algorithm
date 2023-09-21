#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int main(){

    char strs[1010]={0};
    int k;
    scanf("%s %d", strs, &k);
    int index=0;
    char c;
    vector<char> st;
    while((c=strs[index++])!=0){
        while(!st.empty() && c<st.back() && k){// 删除行为
            st.pop_back();
            k--;
        }
        st.push_back(c);
    }

    for(;k>0;k--){
        st.pop_back();
    }

    string ans="";
    int is_leading_zero=1;

    for(auto c:st){
        if(is_leading_zero && c=='0'){
            continue;
        }else{
            is_leading_zero=0;
            ans.push_back(c);
        }

    }

    if(ans==""){
        ans="0";
    }
    cout << ans;


    return 0;
}