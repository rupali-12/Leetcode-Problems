/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    private:
    ListNode* detectLoop(ListNode* &head){
        if(head==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast= head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
            if(slow==fast){
                return slow;
            }
        }
        return NULL;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* intersection= detectLoop(head);
        if(intersection==NULL){
            return NULL;
        }
        ListNode* slow = head;
        while(slow!=intersection){
            intersection = intersection->next;
            slow= slow->next;
        }
        return slow;
    }
};