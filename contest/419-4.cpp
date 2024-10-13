#include "../s.h"


class Solution {
    long long s;
    set<pair<int,int>> s1,s2;
    map<int,int> m;
    int d;
    void ins(int x)
    {
        auto it=m.find(x);
        if(it==m.end())
        {
            m[x]=1;
            s2.insert(make_pair(-1,-x));
        }
        else
        {
            it->second++;
            auto it1=s1.find(make_pair(-it->second+1,-x));
            if(it1!=s1.end())
            {
                s+=x;
                s1.erase(it1);
                s1.insert(make_pair(-it->second,-x));
            }
            else
            {
                s2.erase(make_pair(-it->second+1,-x));
                s2.insert(make_pair(-it->second,-x));
            }
        }
        while(s1.size()<d&&!s2.empty())
        {
            s+=(long long)s2.begin()->first*s2.begin()->second;
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        }
        if(!s1.empty()&&!s2.empty()&&*s2.begin()<*s1.rbegin())
        {
            s+=(long long)s2.begin()->first*s2.begin()->second-(long long)s1.rbegin()->first*s1.rbegin()->second;
            s1.insert(*s2.begin());
            s2.insert(*s1.rbegin());
            s1.erase(*s1.rbegin());
            s2.erase(s2.begin());
        }
    }
    void del(int x)
    {
        auto it=m.find(x);
        auto it1=s1.find(make_pair(-it->second,-x));
        if(it1==s1.end())
        {
            s2.erase(make_pair(-it->second,-x));
            if(it->second==1)m.erase(it);
            else s2.insert(make_pair(-(--it->second),-x));
        }
        else
        {
            s-=x;
            s1.erase(make_pair(-it->second,-x));
            if(it->second==1)m.erase(it);
            else s1.insert(make_pair(-(--it->second),-x));
            while(s1.size()<d&&!s2.empty())
            {
                s+=(long long)s2.begin()->first*s2.begin()->second;
                s1.insert(*s2.begin());
                s2.erase(s2.begin());
            }
            if(!s1.empty()&&!s2.empty()&&*s2.begin()<*s1.rbegin())
            {
                s+=(long long)s2.begin()->first*s2.begin()->second-(long long)s1.rbegin()->first*s1.rbegin()->second;
                s1.insert(*s2.begin());
                s2.insert(*s1.rbegin());
                s1.erase(*s1.rbegin());
                s2.erase(s2.begin());
            }
        }
    }
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        d=x;
        int n=nums.size(),i;
        for(i=0;i+1<k;i++)ins(nums[i]);
        vector<long long> ans;
        for(;i<n;i++)
        {
            ins(nums[i]);
            ans.push_back(s);
            del(nums[i-k+1]);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,1,2,2,3,4,2,3,};
    Solution s;
    printArr(s.findXSum(nums, 6,2));
}