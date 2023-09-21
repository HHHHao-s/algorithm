#include <iostream>
#include <vector>
using namespace std;

int ans=0;
int n;
void hs(int index, vector<int> &arr){
    if(index==n){
        ans++;
        return;
    }
    auto tmp = arr;
    for(int i=index;i<n;i++){
        swap(arr[i], arr[index]);
        if(arr[index]%(index+1)==0 || (index+1)%arr[index]==0){
            hs(index+1, arr);
        }
    }
    arr = tmp;

}

int main(){

    cin >> n;

    vector<int> arr(n);
    for(int i=1;i<=n;i++){
        arr[i-1] = i;
    }
    hs(0, arr);

    cout << ans;


    return 0;
}