#include "s.h"
/*
 * @lc app=leetcode.cn id=1345 lang=cpp
 *
 * [1345] 跳跃游戏 IV
 */

// @lc code=start
class Solution {
private:
    unordered_set<int> vis;

    unordered_map<int,vector<int>> num2pos;
    int target;

    int bfs(vector<int> & arr){
        queue<int> q;
        q.push(0);
        vis.insert(0);
        int step=0;
        while(!q.empty()){
            
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int pos = q.front();
                q.pop();
                if(pos==target){
                    return step;
                }

                if(!num2pos[arr[pos]].empty()){
                    for(int j=num2pos[arr[pos]].size();j-->0;){
                        if(!vis.count(num2pos[arr[pos]][j])){
                            q.push(num2pos[arr[pos]][j]);
                            vis.insert(num2pos[arr[pos]][j]);
                        }
                    
                    }
                    num2pos.erase(arr[pos]);
                }
                

                if(pos>=1){
                    if(!vis.count(pos-1)){
                        q.push(pos-1);
                        vis.insert(pos);
                    }
                }
                if(pos+1<=target){
                    if(!vis.count(pos+1)){
                        q.push(pos+1);
                        vis.insert(pos+1);
                    }
                }
                
            
            }
            step++;
            
            
        }
        return step;
    }

public:
    int minJumps(vector<int>& arr) {
        target = arr.size()-1;
        for(int i=0;i<arr.size();i++){
            num2pos[arr[i]].push_back(i);
        }
        if(target==0){
            return 0;
        }
        return bfs(arr);




    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> arr={
        100,-23,-23,404,100,23,23,23,3,404
    };

    cout << s.minJumps(arr);

    return 0;
}