#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        arr[i] = i;
    }

    for(int i=1;i<=n/2;i++){
        auto tmp = arr;
        int last = 0;
        for(int j=i;j<=n;j+=i){

            arr[j] = tmp[(j-i+n)%n];
            last = j;
        }
        arr[i] = tmp[last];

    }

    for(int i=1;i<=n;i++){

        cout << arr[i] << ' ';

    }

}