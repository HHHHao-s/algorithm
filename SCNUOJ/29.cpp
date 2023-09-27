#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> arr;
    arr.reserve(n);
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    int index=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            
            swap(arr[i], arr[index]);
            index++;
        }
    }

    for(int i=index;i<n;i++){
        if(arr[i]==1){
            swap(arr[i], arr[index]);
            index++;
        }
    }
    cout << "[" << arr[0];
    for(int i=1;i<n;i++){
        cout << ',' << arr[i];
    }
    cout << ']';


    return 0;
}