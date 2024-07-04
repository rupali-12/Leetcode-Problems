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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL || head->next ==NULL) return head;
        ListNode* ans= new ListNode(-1);
        ListNode* temp= ans;
        ListNode* currNode = head->next; 
        int sum=0;
        while(currNode->next!=NULL){
            if(currNode->val==0){
                temp->next= new ListNode(sum);
                temp= temp->next;
                sum=0;
            }
            else{
                 sum+= currNode->val;
            }
            currNode= currNode->next;
        }
        // handle last case 
        temp->next= new ListNode(sum);
        temp= temp->next;
        return ans->next;
    }
};