#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    
    int N;

    map<int, vector<pair<int,int>>> m;

    for(int i=0;i<N;i++){
        int P,X,D;
        cin >> P >> X >>D;

        m[X].push_back({P, D});
    }

    priority_queue<tuple<int,int,int>> pq;

    for(const auto& [day, infos]: m){
        int cur= day;
        while(!pq.empty()){
            auto [p, x,d] = pq.top();
        }

        
        
        
        

    }


}
// 64 位输出请用 printf("%lld")