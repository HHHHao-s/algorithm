#include "s.h"
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        

        ListNode *a=head,*b=head->next;
        head->next=NULL;
        do{
            ListNode *c = b->next;
            b->next = a;
            a= b;
            b= c;
        }while(b!=NULL);

        return a;
    }
};
// @lc code=end


