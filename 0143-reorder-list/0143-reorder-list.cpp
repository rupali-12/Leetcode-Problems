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
    void reorderList(ListNode* head) {
        // find mid 
        ListNode* slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        
        ListNode* midHead= slow->next;
        slow->next= NULL;   // separate both list 
        
        // reverse list from midHead 
        ListNode* prev=NULL, *curr= midHead;
        while(curr!=NULL){
            ListNode* temp= curr->next;
            curr->next= prev;
            prev= curr;
            curr= temp;
        }
        midHead= prev;
        slow->next= NULL;
        
        ListNode* oriHead= head;
        while(midHead!=NULL){
            ListNode* firstNext = oriHead->next;
            ListNode* secondNext= midHead->next;
            
            oriHead->next= midHead;
            midHead->next= firstNext;
            
            oriHead= firstNext;
            midHead= secondNext;
        }    
    }
};