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
        ListNode* temp=head;
        int count=0;

        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;

        int length = findLength(head);
        ListNode* temp=head;

        // Make linkedlist circular
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;

        k = k%length;
        k= length-k;
        while(k--){
            temp= temp->next;
        }

        head= temp->next;
        temp->next=NULL;
        return head;
    }
};


