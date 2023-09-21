#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int main(){

    int a;
    vector<int> arr;
    while(cin>>a){
        arr.push_back(a);
    }

    int l=0,r=arr.size()-1;
    int ans = 0;
    while(l<r){
        int a = arr[l];
        int b = arr[r];

        if(a>b){
            ans = max(ans, b*(r-l));
            r--;
        }else{
            ans = max(ans, a*(r-l));
            l++;
        }
    }

    cout << ans;

    return 0;
}