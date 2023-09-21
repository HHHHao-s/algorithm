#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

void hs(int n, int cur, vector<int>& arr, int target ,int index){
    
    
    if(index==n){
        if(cur==target){
            ans++;
        }
        return;
    }
    
    hs(n, cur+arr[index], arr, target, index+1);
    hs(n, cur-arr[index], arr, target, index+1);

}

int main(){

    int a;
    vector<int> arr;
    arr.reserve(21);
    while(cin>>a){
        arr.push_back(a);
    }
    int target = arr.back();
    arr.pop_back();

    hs(arr.size(), 0, arr, target, 0);

    cout<<ans;

    return 0;
}