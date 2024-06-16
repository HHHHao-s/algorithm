#include "../s.h"

class Solution {
private:
    // pair = {node, ans}
    // 如果node==union_find，ans表明从此节点出发能到达的不同节点的个数
    vector<pair<int,int>> union_find;
    unordered_set<int> visited;
    unordered_set<int> path;

    pair<int,int> find(int x){
        return x==union_find[x].first?union_find[x]:union_find[x]=find(union_find[x].first);
    }

    void merge(int x, int y){
        auto [fx,tx] = find(x);
        auto [fy,ty] = find(y);
        if(fx!=fy){
            union_find[fx].first = fy;
            union_find[fy].second += union_find[fx].second;
        }
    }

    /** 返回值：type, data
     *  当type==0时，表示当前路径下的遇到了一个环的交叉点
     *  此时data为这个交叉点的节点号，然后在回溯的过程中，若没有回溯到交叉点，就将此节点加入交叉点的并查集中，并查集会记录在同一集合下的点的个数
     *  若回溯到交叉节点，则返回{type=1, data=ans}
     *  当返回值type==1时，表明我们遇到了一个环的交叉点或者一条非环路径的节点，此时可以直接将data记录在以这个节点为根的并查集上
     *  然后返回data+1
    */
    pair<int,int> dfs(int node, vector<int>& edges){
        

        visited.insert(node);
        path.insert(node);
        if(path.count(edges[node])){
            // 遇到环，将此节点加入并查集
            merge(node, edges[node]);
            return {0,edges[node]};
        }else if(visited.count(edges[node])){
            // 遇到已经访问过的节点，直接获得这个节点的ans，并记录和返回
            union_find[node].second = find(edges[node]).second+1;
            return {1, union_find[node].second};
        }else{
            // 继续dfs
            auto [type,cross] = dfs(edges[node], edges);
            if(type==0 && cross!=node){
                // 如果返回了0且交叉点不是此节点，我们要把此节点加入这个集合里
                merge(node, cross);
                return {0, cross};
            }else if(type==0 && cross==node){
                // 如果返回了0且此节点为交叉点，既然我们已经将此节点加入到集合里了，我们就直接返回这个节点的ans
                return {1, find(node).second};
            }
            else if(type==1){
                // 如果返回了1，表明此节点的下一个节点不是一个环上的节点或是一个环的交叉点，我们就更新记录，并返回这个节点的ans
                union_find[node].second = cross+1;
                return {1, cross+1};
            }
        }
        // 不会到这里
        return {-1,-1};
        
    }

public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        union_find.resize(n);
        for(int i=0;i<n;i++){
            union_find[i] = {i,1};
        }
        vector<int> ret;
        ret.reserve(n);
        for(int i=0;i<n;i++){
            if(!visited.count(i)){
                dfs(i,edges);
                
                path.clear();
            }
            // 当我们从此节点出发开始dfs，这个节点所在的子集的父节点就记录着ans
            ret.push_back(find(i).second);
        }
        return ret;
    }
};

int main(){

    Solution s;
    vector<int> edges={
        8,17,14,8,14,12,16,11,4,14,19,6,8,8,2,10,2,1,1,18
    };
    vector<vector<int>> adj_arr(edges.size());
    for(int i=0;i<edges.size();i++){
        adj_arr[i].push_back(edges[i]);
    }

    // generateDotFile(adj_arr, "365-4.dot");

    printArr(s.countVisitedNodes(edges));


    return 0;
}