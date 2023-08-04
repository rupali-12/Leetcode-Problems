/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int findLength(ListNode* head){
        int cnt=0;
        ListNode* temp= head;
        while(temp!=NULL){
            cnt++;
            temp= temp->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL && headB==NULL){
            return NULL;
        }
        int lenA= findLength(headA);
        int lenB =findLength(headB);
      
        if(lenA>lenB){
            while(lenA> lenB){
                headA= headA->next;
                lenA--;
            }
        }
        else if(lenB> lenA){
             while(lenA< lenB){
                headB= headB->next;
                lenB--;
            }
        }
        while(headA!=NULL && headB!=NULL){
            if(headA==headB){
                return headA;
            }
            headA= headA->next;
            headB= headB->next;
        }
        
        return NULL;
    }
};