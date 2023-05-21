#include "s.h"
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)return true; // single node
        if(head->next->next == NULL)return (head->val == head->next->val); // two node
        if(head->next->next->next == NULL) return (head->val == head->next->next->val); // three node
        


        // reverse the half
    
        ListNode *a=head,*b=a->next, *p = b->next,*c=NULL;
        head->next=NULL;
        do{
            c=b->next;
            b->next = a;
            a= b;
            b= c;
            p = p->next->next;
        }while(p!=NULL && p->next!=NULL);

        
        if(p!=NULL){ // odd
            b = b->next;
        }  
        
        while(a && b && (a->val == b->val)){
                a=a->next;
                b=b->next;

        }
        if(a==NULL && b== NULL){
            return true;
        }else{
            return false;
        }


    }
};
// @lc code=end

int main(){

    int l[] = {1,2,0,0,2,1};

    ListNode * head = new ListNode(l[0]);
    ListNode * p = head;
    for(int i=1;i<sizeof(l)/sizeof(l[0]);i++){
        
        p->next = new ListNode(l[i]);
        p=p->next;
    }

    Solution sl;
    cout << sl.isPalindrome(head);

    return 0;

}