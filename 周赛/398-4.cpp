#include "../s.h"


// class Solution {
// public:
//     int dfs(int cur, int step, int back){
//         int ways = 0;
//         if(back){
//             ways = dfs(cur+1, step, 0);
//         }
//         if(cur < (1<<step))

//     }

//     int waysToReachStair(int k) {
        
//         if(k==0){
//             return 2;
//         }
//         if(k==1 ){
//             return 4;
//         }

        

//     }
// };


class Solution {
public:
   

    int waysToReachStair(int k) {
        
        // queue<tuple<int,int, int>> q;

        // q.push({1,0,0});
        unordered_map<int, unordered_map<int, int>> b1;
        unordered_map<int, unordered_map<int, int>> b2;
        // int ans= 0;
        function<int(int,int,int)> dfs = [&](int cur, int step, int back){

            if(back && b1.count(cur) && b1[cur].count(step)){
                return b1[cur][step];
            }else if(!back && b2.count(cur) && b2[cur].count(step)){
                return b2[cur][step];
            }
            int w = 0;
            if(cur == k){
                w++;
            }
            if(!back && cur-1>=0){
                w += dfs(cur-1, step, 1);
            }
            if(cur+(1<<step)-1>k){
                if(back){
                    b1[cur][step]=w;
                }else{
                    b2[cur][step]=w;
                }
                return w;
            }
            w += dfs(cur+(1<<step), step+1, 0);

            if(back){
                b1[cur][step] = w;
            }else{
                b2[cur][step] = w;
            }

            return w;



        };
        return dfs(1, 0, 0);

    }
};

int main(){
    Solution s;
    cout << s.waysToReachStair(1);
}