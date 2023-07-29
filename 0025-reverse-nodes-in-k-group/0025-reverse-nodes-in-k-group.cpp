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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size=0;
        ListNode* temp= head;
        while(temp!=NULL){
            temp= temp->next;
            size++;
        }
        if(size<k){
            return head;
        }
         ListNode*prev=NULL, *curr=head, *next= NULL;
        int cnt=0;
     while(curr!=NULL && cnt<k){
         next= curr->next;
         curr->next= prev;
         prev=curr;
         curr=next;
         cnt++;
     }
        if(curr!=NULL){
            head->next= reverseKGroup(curr, k);
        }
        return prev;
        
    }
};