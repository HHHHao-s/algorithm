#include "s.h"
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
class Solution{
public:
    ListNode * mergeTwoLists(ListNode *list1, ListNode * list2){
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        ListNode *head;
        
        if(list1->val > list2->val){
            head = new ListNode(list2->val);
            list2=list2->next;
        }else{
            head = new ListNode(list1->val);
            list1=list1->next;
        }
        ListNode *ans = head;
        while(list1 && list2){
            if(list1->val > list2->val){
                ans->next = new ListNode(list2->val);
                ans=ans->next;
                list2=list2->next;
            }else{
                ans->next = new ListNode(list1->val);
                ans=ans->next;
                list1=list1->next;
            } 
        }

        while(list1){
            ans->next = new ListNode(list1->val);
            ans=ans->next;
            list1=list1->next;
        }
        while(list2){
            ans->next = new ListNode(list2->val);
            ans=ans->next;
            list2=list2->next;
        }


        return head;

    }
};
// @lc code=end

