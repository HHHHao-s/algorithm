#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
using namespace std;

set<string> ans;

void hs(int open, int  closed, string cur,int n){

    if(cur.size() == n*2){
        ans.insert(cur);
    }

    if(open<n){
        cur.push_back('(');
        hs(open+1, closed, cur, n);
        cur.pop_back();
    }
    if(closed<open){
        cur.push_back(')');
        hs(open, closed+1, cur, n);
        cur.pop_back();
    }



}

int main(){

    int n;
    cin >> n;
    hs(0,0,"",n);
    cout <<"[";
    for(auto s=ans.begin();s != ans.end();s++){
        
        auto tmp = s;
        if(++tmp == ans.end()){
            cout << *s;
            break;
        }else{
            cout << *s << ", ";
        }

    }
    cout << "]";


    return 0;
}