#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

char a[10][5]={
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

vector<string> ans;

void hs(char cur[5], int high, int n, int num, int for_divide){
    if(high==n){
        ans.push_back(cur);
        return;
    }
    int cur_digit = (num/for_divide)%10;
    int range= strlen(a[cur_digit]);
    for(int i=0;i<range;i++){
        cur[high] = a[cur_digit][i];
        hs(cur, high+1,n,num, for_divide/10);
        
    }

}

int main(){
    int num;
    cin >> num;
    char cur[5]="";
    int n=0;
    int for_divide=1;
    int tmp = num;
    while(num){
        num/=10;
        n++;
        for_divide*=10;
    }

    hs(cur, 0,n,tmp, for_divide/10);

    cout << "[";
    cout << ans.front();

    int whole = ans.size();
    for(int i=1;i<whole;i++){
        cout << ", " << ans[i];
    }
    cout << "]";


    return 0;
}