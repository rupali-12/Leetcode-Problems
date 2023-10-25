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
    int findLength(ListNode* head){
        if(head==NULL) return 0;
        int count=0;
        ListNode* temp= head;
        while(temp!=NULL){
            count++;
            temp= temp->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        
        int len = findLength(head);
        ListNode* temp= head;
        
        // make linkedlist as circular 
        while(temp->next){
            temp= temp->next;
        }
        temp->next= head;
        
        k= k%len;
        k= len-k;
        while(k--){
            temp= temp->next;
        }
       head =temp->next;
       temp->next=NULL;
        
     return head; 
    }
};