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
    int getLength(ListNode* head){
        if(head==NULL) return 0;
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp=head;
        int i=0;
        int mid = getLength(head)/2;
        if(head==NULL || head->next==NULL) return NULL;
       while(i<mid){
          if(i==0) temp=head;
          else temp= temp->next;
           i++;
       }
       temp->next = temp->next->next;
       return head;
    }
};