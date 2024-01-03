#include "s.h"
/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode *p = head;

        deque<ListNode*> st;
        while(p){
            while(!st.empty() && p->val>st.back()->val){
                st.pop_back();
                
            }
            st.push_back(p);
            p=p->next;
        }
        head = st.front();
        st.pop_front();
        p=head;
        while(!st.empty()){
            p->next = st.front();
            st.pop_front();
            p=p->next;
        }
        p->next=nullptr;
        return head;

    }
};
// @lc code=end

