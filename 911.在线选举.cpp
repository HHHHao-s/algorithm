#include "s.h"
/*
 * @lc app=leetcode.cn id=911 lang=cpp
 *
 * [911] 在线选举
 */

// @lc code=start
class TopVotedCandidate {
private:
    
    map<int,int> time_winner;
    
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {

        map<int,stack<int>> st;
        unordered_map<int, int> votes;
        int n = persons.size();
        

        for(int i =0;i<n;i++){

            int time = times[i];
            int person = persons[i];
            votes[person]++;
            st[votes[person]].push(person);
            time_winner[time]=st.rbegin()->second.top();

        }
    }
    
    int q(int t) {
        auto it = --time_winner.upper_bound(t);
      
        return it->second;

    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end

int main(){
    vector<int>persons={0,1,1,0,0,1,0};
    vector<int> times={0,5,10,15,20,25,30};
    TopVotedCandidate(persons, times);



}