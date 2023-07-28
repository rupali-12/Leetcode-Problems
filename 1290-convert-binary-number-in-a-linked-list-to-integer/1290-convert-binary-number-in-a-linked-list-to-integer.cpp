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
   ListNode* rev(ListNode* head){
        if(head==NULL || head->next==NULL){
           return head;
       }
        ListNode* ans= rev(head->next);
        head->next->next= head;
        head->next= NULL;
        return ans;
   }
    int getDecimalValue(ListNode* head) {
      ListNode* revLL = rev(head);
      ListNode* temp = revLL;  
        int ans=0, i=0;
        while(temp!=NULL){
            ans= ans+ temp->val* pow(2, i);
            i++;
            temp= temp->next;
        }
        return ans;
    }
};