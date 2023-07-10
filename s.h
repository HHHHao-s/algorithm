// C++
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

TreeNode *genTree(vector<long long> testcase)
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
    int nulls=0;
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
                if(nulls!=0){
                    for(int i=0;i<nulls;i++){
                        cout << "null ";
                    }
                    nulls=0;
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

template<typename T>
void print2d(const vector<vector<T>> nums){
    cout<<"[";
    
    if(nums.size()>0){
        cout<<"[";
        if(nums[0].size()>0){
            cout << nums[0][0];
        }
        
        for(int j=1; j<nums[0].size(); j++){
            cout << ","<< nums[0][j];
        }
        cout << "]";
    }
    

    for(int i=1; i<nums.size(); i++){
        cout<<",[";
        if(nums[i].size()>0){
            cout << nums[i][0];
        }
        
        for(int j=1; j<nums[i].size(); j++){
            cout << ","<< nums[i][j];
        }
        cout << "]";
    }
    cout <<"]";
}

template<typename T>
void printArr(vector<T> arr){
    cout << "[";
    if(arr.size()>0){
        cout << arr[0];
    }
    
    for(int j=1; j<arr.size(); j++){
        cout << ","<< arr[j];
    }
    cout << "]";
    
}