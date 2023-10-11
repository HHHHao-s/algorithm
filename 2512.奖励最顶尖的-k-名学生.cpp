#include "s.h"
/*
 * @lc app=leetcode.cn id=2512 lang=cpp
 *
 * [2512] 奖励最顶尖的 K 名学生
 */

// @lc code=start
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        map<int,int> id2score;
        unordered_set<string> pos,neg;

        for(int i=0;i<positive_feedback.size();i++){
            pos.insert(positive_feedback[i]);   
        }
        for(int i=0;i<negative_feedback.size();i++){
            neg.insert(negative_feedback[i]);
        }
        int n = student_id.size();
        
        for(int i=0;i<n;i++){
            string s = report[i];
            size_t last=0;
            id2score[student_id[i]]=0;
            for(auto it=s.begin();it!=s.end();it++){
                if(*it==' '){
                    string word = s.substr(last, it-s.begin()-last);
                    cout << word << endl;
                    if(pos.count(word)){
                        id2score[student_id[i]]+=3;
                    }else if(neg.count(word)){
                        id2score[student_id[i]]--;
                    }
                    last = it-s.begin()+1;
                }
            }
            string word = s.substr(last, s.size()-last);
            cout << word << endl;
            if(pos.count(word)){
                id2score[student_id[i]]+=3;
            }else if(neg.count(word)){
                id2score[student_id[i]]--;
            }
        }
        
        map<int, vector<int>> score2id;
        for(auto [id,score]: id2score){
            score2id[score].push_back(id);
        }

        vector<int> ret;
        for(auto it = score2id.rbegin();it!=score2id.rend();it++){
            auto& [id,vec] = *it;
            for(auto id: vec){
                
                ret.push_back(id);
                if(ret.size()==k){
                    return ret;
                }
            }
        }

        return ret;



    }
};
// @lc code=end

int main(){
    Solution s;

    

    return 0;
}