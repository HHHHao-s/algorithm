#include "s.h"
/*
 * @lc app=leetcode.cn id=928 lang=cpp
 *
 * [928] 尽量减少恶意软件的传播 II
 */

// @lc code=start
class Solution {
public:
    vector<int> parent, size;
    void initUnion(int len){
        parent.resize(len);
        size.resize(len);
        for(int i = 0; i < len; i ++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    int getSize(int x){
        return size[find(x)];
    }

    void merge(int a, int b){
        int pa = find(a), pb = find(b);
        if(pa == pb){
            return;
        }
        parent[pb] = pa;
        size[pa] += size[pb];
    }

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();

        initUnion(n);

        // 第一步，将初始没有被污染的点建立并查集
        vector<int> cleanNode(n, 1); // 未污染点，初始值为1
        for(int num: initial){ // 将被污染点的对应位置变为0
            cleanNode[num] = 0;
        }
        for(int i = 0; i < n; i ++){ // 合并未污染区间
            if(cleanNode[i] == 1){
                for(int j = 0; j < n; j ++){
                    if(cleanNode[j] == 1 && graph[i][j] == 1){
                        merge(i, j);
                    }
                }
            }
        }

        // 第二步，统计每个污染点可以到达的未污染点区间;并记录每个未污染区间可以被多少污染点到达
        vector<int> count(n, 0); // 可到达未污染区间的污染点个数，初始值为0
        map<int, set<int>> dirtyToClean; // 污染点到未污染区间的map
        for(int dirty: initial){ // 遍历污染点
            set<int> toClean;
            for(int clean = 0; clean < n; clean ++){ // 记录该污染点可以到达的未污染区间
                if(cleanNode[clean] == 1 && graph[dirty][clean] == 1){
                    toClean.insert(find(clean));
                }
            }

            dirtyToClean.insert({dirty, toClean}); // 将污染点和对应的可到达区间压入map

            for(int clean :toClean){ // 统计可到达的个数
                count[clean]++;
            }
        }

        // 第三步，找到只能被一个污染点到达的未污染区间，该污染点删除后，整个区间都能够不被污染
        int tempSize = -1,  res = -1;
        for(auto iter : dirtyToClean) { // 遍历所有污染点和可到达的未污染区间
            set<int> toClean = iter.second;
            int tempSize1 = 0;
            for(int clean: toClean){
                if(count[clean] == 1){ // 如果该区间只有一个污染点可以到达，则删除污染点有意义
                    tempSize1 += getSize(clean);
                }
            }

            if(tempSize1 > tempSize || (tempSize1 == tempSize && iter.first < res)){ // 判断tempsize和res
                tempSize = tempSize1;
                res = iter.first;
            }
        }

        return res;
    }
};

// @lc code=end

int main(){
    Solution s;
    vector<int> inital = {8,4,2,0};
    cout << s.minMalwareSpread({
        {1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,1},
        {0,0,1,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,1},
        {0,0,0,0,1,0,1,1,1},
        {0,0,0,0,0,1,0,0,1},
        {0,0,0,0,1,0,1,1,0},
        {0,0,0,0,1,0,1,1,0},
        {0,1,0,1,1,1,0,0,1}
    },inital);
    // vector<int> inital = {0,1};
    // cout << s.minMalwareSpread({
    //    {1,1,0},
    //    {1,1,0},
    //    {0,0,1}
    // },inital);
}