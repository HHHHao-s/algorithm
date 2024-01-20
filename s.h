// C++
#pragma once
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define null INT64_MIN

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *_next) : val(x), next(_next) {}
};

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

ListNode *genList(vector<int> testcase)
{ // 根据testcase生成链表
    ListNode *head = new ListNode(testcase[0]), *p = head;
    int n = testcase.size();
    for (int i = 1; i < n; i++)
    {
        p->next = new ListNode(testcase[i]);
        p = p->next;
    }
    return head;
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *genTree(const vector<long long> testcase)
{
    if (testcase.size() == 0)
        return nullptr;

    TreeNode *head = new TreeNode(testcase[0]);

    queue<TreeNode *> q;
    q.push(head);

    int index = 1;
    int n = testcase.size();
    while (index < n)
    {

        TreeNode *p = q.front();
        q.pop();

        long long tmp = testcase[index++];
        if (tmp != null)
        {
            p->left = new TreeNode(tmp);
            q.push(p->left);
        }
        tmp = testcase[index++];
        if (tmp != null)
        {
            p->right = new TreeNode(tmp);
            q.push(p->right);
        }
    }

    return head;
}

void printTree(TreeNode *root)
{

    queue<TreeNode *> q;
    int nulls = 0;
    q.push(root);
    while (!q.empty())
    {
        int currentLevelSize = q.size();

        for (int i = 1; i <= currentLevelSize; ++i)
        {

            auto node = q.front();
            q.pop();
            if (node != nullptr)
            {
                if (nulls != 0)
                {
                    for (int i = 0; i < nulls; i++)
                    {
                        cout << "null ";
                    }
                    nulls = 0;
                }
                cout << node->val << ' ';
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                nulls++;
            }
        }
    }
    cout << endl;
}

template <typename T>
void print2d(const vector<vector<T>> nums)
{
    cout << "[";

    if (nums.size() > 0)
    {
        cout << "[";
        if (nums[0].size() > 0)
        {
            cout << nums[0][0];
        }

        for (int j = 1; j < nums[0].size(); j++)
        {
            cout << "," << nums[0][j];
        }
        cout << "]";
    }

    for (int i = 1; i < nums.size(); i++)
    {
        cout << ",[";
        if (nums[i].size() > 0)
        {
            cout << nums[i][0];
        }

        for (int j = 1; j < nums[i].size(); j++)
        {
            cout << "," << nums[i][j];
        }
        cout << "]";
    }
    cout << "]";
}

template <typename T>
void printArr(vector<T> arr)
{
    cout << "[";
    if (arr.size() > 0)
    {
        cout << arr[0];
    }

    for (int j = 1; j < arr.size(); j++)
    {
        cout << "," << arr[j];
    }
    cout << "]";
}

void generateDotFile(const vector<vector<int>> &adjList, const string &filename)
{
    ofstream fout(filename);
    fout << "digraph G {" << endl;
    for (int i = 0; i < adjList.size(); i++)
    {
        for (int j = 0; j < adjList[i].size(); j++)
        {
            fout << i << " -> " << adjList[i][j] << ";" << endl;
        }
    }
    fout << "}" << endl;
    fout.close();
}

/*

struct UnionFind{
    UnionFind() = default;

    UnionFind(size_t n): arr(n){
        for(int i=0;i<n;i++){
            arr[i] = {i,1};
        }
        region = n;
    }

    int Find(int x){
        return arr[x].fa==x?x:(arr[x].fa=Find(arr[x].fa));
    }
    void Union(int x, int y){
        int fax = Find(x);
        int fay = Find(y);
        if(fax!=fay){
            if(arr[fax].cnt<arr[fay].cnt){
                swap(fax, fay);
            }
            // 把fay合并到fax
            arr[fax].cnt += arr[fay].cnt;
            arr[fay].fa = fax;
            region--;
        }
    }
    int& GetCnt(int x){
        return arr[Find(x)].cnt;
    }

    struct Info{
        int fa,cnt;
    };
    vector<Info>  arr;
    int region{0};
};

*/
/*
// 顺序生成回文数，一共10999个（包括哨兵）
vector<int> pal;

auto init = [] {
    // 严格按顺序从小到大生成所有回文数（不用字符串转换）
    for (int base = 1; base <= 10000; base *= 10) {
        // 生成奇数长度回文数
        for (int i = base; i < base * 10; i++) {
            int x = i;
            for (int t = i / 10; t; t /= 10) {
                x = x * 10 + t % 10;
            }
            pal.push_back(x);
        }
        // 生成偶数长度回文数
        if (base <= 1000) {
            for (int i = base; i < base * 10; i++) {
                int x = i;
                for (int t = i; t; t /= 10) {
                    x = x * 10 + t % 10;
                }
                pal.push_back(x);
            }
        }
    }
    pal.push_back(1'000'000'001); // 哨兵，防止下面代码中的 i 下标越界
    return 0;
}();

// 顺序生成回文数，一共109999个（包括哨兵）
vector<long long> pal;

auto init = [] {
    // 严格按顺序从小到大生成所有回文数（不用字符串转换）
    for (long long base = 1; base <= 100000; base *= 10) {
        // 生成奇数长度回文数
        for (long long i = base; i < base * 10; i++) {
            long long x = i;
            for (int t = i / 10; t; t /= 10) {
                x = x * 10 + t % 10;
            }
            pal.push_back(x);
        }
        // 生成偶数长度回文数
        if (base <= 10000) {
            for (long long i = base; i < base * 10; i++) {
                long long x = i;
                for (long long t = i; t; t /= 10) {
                    x = x * 10 + t % 10;
                }
                pal.push_back(x);
            }
        }
    }
    

    pal.push_back(100000000001); // 哨兵，防止下面代码中的 i 下标越界
}
*/



/*

template <typename T>
inline void hash_combine(std::size_t &seed, const T &val) {
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
// auxiliary generic functions to create a hash value using a seed
template <typename T> inline void hash_val(std::size_t &seed, const T &val) {
    hash_combine(seed, val);
}
template <typename T, typename... Types>
inline void hash_val(std::size_t &seed, const T &val, const Types &... args) {
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline std::size_t hash_val(const Types &... args) {
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        return hash_val(p.first, p.second);
    }
};

*/

// 树状数组
/*
class BITree{
public:
    BITree(const vector<int>& in_nums):nums(in_nums),info(in_nums.size()+1) {
        for (int i = 1; i <= in_nums.size(); i++) {
            info[i] += in_nums[i - 1];
            int nxt = i + (i & -i); // 下一个关键区间的右端点
            if (nxt <= in_nums.size()) {
                info[nxt] += info[i];
            }
        }
    }
    
    void increase(int index, int delta){
        nums[index]+=delta;
        index++;
        for(;index<info.size();index += (index&(-index))){
            info[index] += delta;
        
        }
    }
    void update(int index, int val){
        int delta = val-nums[index];
        nums[index] = val;
        index++;
        for(;index<info.size();index += (index&(-index))){
            info[index] += delta;
        
        }
    }
    // left==-1 会直接返回0 [0,index]
    int query(int index){
        int ret =0;
        index++;
        for(;index>0;index-=(index&(-index))){
            ret += info[index];
        }
        return ret;
    }
    //[left, right]
    int queryRange(int left, int right){ 
        
        return query(right)- query(left-1);
        
    }
private:
    vector<int> nums;
    vector<int> info;
    int n;
};
*/

/*
class SegmentTree { // 区间最大值线段树
private:
    vector<int> segmentTree;
    int n;

    void build(int node, int s, int e, vector<int> &nums) {
        if (s == e) {
            segmentTree[node] = nums[s];
            return;
        }
        int m = s + (e - s) / 2;
        build(node * 2 + 1, s, m, nums);
        build(node * 2 + 2, m + 1, e, nums);
        segmentTree[node] = max(segmentTree[node * 2 + 1] ,segmentTree[node * 2 + 2]);
    }

    void change(int index, int val, int node, int s, int e) {
        if (s == e) {
            segmentTree[node] = val;
            return;
        }
        int m = s + (e - s) / 2;
        if (index <= m) {
            change(index, val, node * 2 + 1, s, m);
        } else {
            change(index, val, node * 2 + 2, m + 1, e);
        }
        segmentTree[node] = max(segmentTree[node * 2 + 1] , segmentTree[node * 2 + 2]);
    }

    int range(int left, int right, int node, int s, int e) {
        if (left == s && right == e) {
            return segmentTree[node];
        }
        int m = s + (e - s) / 2;
        if (right <= m) {
            return range(left, right, node * 2 + 1, s, m);
        } else if (left > m) {
            return range(left, right, node * 2 + 2, m + 1, e);
        } else {
            return max(range(left, m, node * 2 + 1, s, m) , range(m + 1, right, node * 2 + 2, m + 1, e));
        }
    }

public:
    SegmentTree(vector<int>& nums) : n(nums.size()), segmentTree(nums.size() * 4) {
        build(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        change(index, val, 0, 0, n - 1);
    }

    int mxRange(int left, int right) {
        return range(left, right, 0, 0, n - 1);
    }
};
*/

/*
class Trie{
public:
    Trie() = delete;
    Trie(int range_):range(range_) ,sons(range_){

    }

    void insert(const string& str){
        Trie *cur = this;
        for(char c: str){
            if(cur->sons[c-'a']==nullptr){
                cur->sons[c-'a'] = new Trie(range);
            }
            cur = cur->sons[c-'a'];

        }
        cur->count++;
        

    }

    ~Trie(){
        for(auto t: sons){
            delete t;
        }
    }

private:
    int range{0};
    int count{0};
    vector<Trie*> sons;
};
*/

/*
// 数位dp模板
function<int(int, int, bool, bool)> f = [&](int i, int mask, bool is_limit, bool is_num) -> int {
    if (i == m)
        return is_num; // is_num 为 true 表示得到了一个合法数字
    if (!is_limit && is_num && memo[i][mask] != -1)
        return memo[i][mask];
    int res = 0;
    if (!is_num) // 可以跳过当前数位
        res = f(i + 1, mask, false, false);
    int up = is_limit ? s[i] - '0' : 9; // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
    for (int d = 1 - is_num; d <= up; ++d) // 枚举要填入的数字 d
        if ((mask >> d & 1) == 0) // d 不在 mask 中
            res += f(i + 1, mask | (1 << d), is_limit && d == up, true);
    if (!is_limit && is_num)
        memo[i][mask] = res;
    return res;
};
*/