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
        int cnt=0;
        ListNode* temp= head;
        while(temp!=NULL){
            cnt++;
            temp= temp->next;
        }
        return cnt;
    }
    void deleteNode(ListNode* &head, int count, int length){
        if(count==1){
            head= head->next;
            cout<<head->val;
            return;
        }
        // cout<<count<<length;
        ListNode* temp= head;
        int i=1;
        while(i<count-1){
            i++;
            temp=temp->next;
        }
        temp->next= temp->next->next;
        return;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL && n==1){
            return NULL;
        }
        int length= getLength(head);
        int cntFromStart= length-n+1;
        if(length>=n){
              deleteNode(head, cntFromStart, length);
        }
        return head;
    }
};