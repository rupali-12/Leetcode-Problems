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
    int ans=0;
    ListNode* temp = head;
    while(temp!=NULL){
        ans++;
        temp= temp->next;
    }
    return ans;
}
void deleteFromStart(ListNode* &head, int nodeFromStart){
    if(nodeFromStart==1){
        head= head->next;
        return;
    }
    int i=1;
    ListNode* temp = head;
    while(i < nodeFromStart-1){
        temp= temp->next;
        i++;
    }
    temp->next =temp->next->next;
    return;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
          return NULL;
        }
        int length =findLength(head);

        int nodeFromStart = length - n+1;
        if(length >= nodeFromStart){
            deleteFromStart(head, nodeFromStart);
        }
        return head;
    }
};