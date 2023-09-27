#include <vector>
#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> arr;
    arr.reserve(n);
    int a;
    for(int i=0;i<n;i++){
        cin >> a;
        arr.push_back(a);
    }

    int times=0;
    int end=0;
    int most_right=0;

    for(int i=0;i<n-1;i++){

        most_right = max(most_right, arr[i]+i);
        if(i == end){
            end = most_right;
            times++;
        }

    }

    cout << times;

    return 0;
}