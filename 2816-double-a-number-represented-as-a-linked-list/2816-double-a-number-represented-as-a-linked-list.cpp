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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next= prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        // Approach-1: using reversing 
       ListNode* revList=  reverse(head);
        
        ListNode* temp= revList, *last=revList;
        
        int carry=0;
        while(temp!=NULL){
            if(temp->next==NULL){
                last= temp;
            }
          int data = temp->val*2 + carry;
            temp->val= data%10;
            carry= data/10;
            temp= temp->next;
        }
        
        if(carry!=0){
            ListNode* newHead= new ListNode(carry);
            last->next= newHead;
            last= newHead;
        }
        
        head =reverse(revList);
        
      return head;
    }
};