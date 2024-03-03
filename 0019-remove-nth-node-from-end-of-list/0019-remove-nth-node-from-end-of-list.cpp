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
        ListNode* temp= head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp= temp->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;
        
        int length= findLength(head);
        int nodeFromStart= length - n +1;
        
        // case of delete first node 
        if(nodeFromStart==1){
            head= head->next;
            return head;
        }
        
        // Delete any other node 
        ListNode* temp= head;
        int i=1;
        while(i<nodeFromStart-1){
            i++;
            temp=temp->next;
        }
        temp->next= temp->next->next;
        return head;
    }
};