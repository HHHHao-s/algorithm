#include "s.h"
/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start

class Solution {
public:
    // 归并排序
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;

        int k= 1; // 比较一组的数量
        int begin=1; // 当最开始时，要对head进行更改 
        ListNode *pgroup=head;
        ListNode *par = nullptr; 
        while(1){
            ListNode *p1=pgroup,*p2=p1;
            for(int i=0;i<k;i++){
                p2 = p2->next;
                if(p2==nullptr){
                    if(p1==head) return head; // 这时，已经结束了  
                    else {
                        par->next = p1;// 让上一个指向这里
                        break;
                    } // 不用管
                }
            }
            
            
            if(p2==nullptr){
                k*=2;
                pgroup = head;
                begin=1;
                par = nullptr;
                continue;
            }
            

            ListNode *p = nullptr;
            int n1=0,n2=0;
            while(p1 && p2 && n1<k && n2<k){ // p1,p2这时开始，分别是有序的链表
                ListNode**pwinner = p1->val<=p2->val?&p1:&p2;// 小的那个
                
                int *n = p1->val<=p2->val?&n1:&n2;
                if(p == nullptr){
                    p = *pwinner;
                    *pwinner = (*pwinner)->next;
                    if(begin==1){
                        if(head->val >= p->val){
                            head= p;
                        }
                        begin = 0;
                    }else{
                        par->next = p;
                    }
                }
                else{
                    ListNode *tmp = *pwinner;
                    *pwinner = (*pwinner)->next;   
                    p->next = tmp;
                    p = p->next;
                }           
                (*n)++;   
            }

            if(p2==nullptr){
                p->next = p1;
                for(int i=0;i<k-n1;i++){
                    p=p->next;
                }
                p->next  =nullptr;// 断开尾巴
                k*=2;
                pgroup = head;
                begin=1;
                par = nullptr;
                continue;
            }

            if(n2==k){ // p2正常跑完
        
                p->next = p1;
                for(int i=0;i<k-n1;i++){
                    p=p->next;
                }
                p->next  =nullptr;
                par = p; // 上一段链表的尾巴
                
                pgroup = p2;
            }else if(n1==k){ // p1 正常跑完
                p->next = p2; 
                for(int i=0;i<k-n2 && p->next;i++){ // 可能会遇到nullptr
            
                    p=p->next; // 去到末尾
                }
                pgroup = p->next;
                p->next  =nullptr;
                par = p; // 上一段链表的尾巴

            }

            if(pgroup==nullptr){
                k*=2;
                pgroup = head;
                begin=1;
                par = nullptr;
            }
        }

        return NULL;
    }
};
// @lc code=end


class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};



int main(){


    

    Solution sl;
    
    // for(int i=10;i<1000;i++){
    //     vector<int> vec(i,0);
    //     int a= 0;
    
    //     for(auto it: vec){
    //         it = a++;
    //     }
    //     random_shuffle(vec.begin(),vec.end());
        
    //     ListNode*p = sl.sortList(genList(vec));
    //     sort(vec.begin(),vec.end());
    //     auto it = vec.begin();
    //     for(;p;p=p->next){
    //         if(p->val != *it++) cout << "shit\n";
    //     }
    //     cout << vec.size() << "cool\n";
    // }
    
    printList(sl.sortList(genList({1,2,2,1,1,3,3,3,3,1,1,2,2,1})));


    return 0;
}
