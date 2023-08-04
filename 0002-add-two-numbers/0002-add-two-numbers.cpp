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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode* ans= new ListNode(-1);
        ListNode* n= ans;
    int carry=0;
        while(l1!=NULL && l2!=NULL){
            int val = l1->val + l2->val + carry;
            carry= val/10;
            ListNode* temp = new ListNode(val%10);
            n->next=temp;
            n= temp;
            l1= l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
             int val = l1->val + carry;
            carry= val/10;
            ListNode* temp = new ListNode(val%10);
            n->next=temp;
            n= temp;
            l1= l1->next;
        }
        while(l2!=NULL){
             int val = l2->val + carry;
            carry= val/10;
            ListNode* temp = new ListNode(val%10);
            n->next=temp;
            n= temp;
            l2=l2->next;
        }
        if(carry){
             ListNode* temp = new ListNode(carry);
            n->next=temp;
        }
        return ans->next;
    }
};