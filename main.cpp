#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <algorithm>
#include <future>
#include <thread> // 包含sleep_for
#include <chrono> // 包含chrono_literals
#include <deque>
#include <time.h>
#include <random>
using namespace std;

int n;

int main(){
    cin >> n;
    struct Node{
        long long l,r,t,d;

    };

    vector<Node> each_node;
    map<long long, vector<Node>> time_each;
    for(int i=0;i<n;i++){
        long long l,r,t,d;
        cin >> l >> r >> t >> d;
        each_node.push_back({l,r,t,d});
        
    }
    sort(each_node.begin(), each_node.end(), [](const Node&a, const Node&b){
        return a.l< b.l;
    });
    long long s=0;
    long long cur_time=0;

    for(int i=0;;){

        while(i<n && s>=each_node[i].l){
            if(s<=each_node[i].r){
                time_each[cur_time + each_node[i].t].push_back(each_node[i]);
            } 
            i++;
        }
        if(time_each.empty()){
            break;
        }
        long long add=0;
        cur_time = time_each.begin()->first;
        for(auto &&node: time_each[cur_time]){
            if(s<=node.r){
                add+= node.d;
            }
        }
        time_each.erase(cur_time);  
        s+=add;
    }
    cout << s;

}




