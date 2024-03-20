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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* first= list1, *second= list2;
        int i=0;
        
        // place first at (a-1)th place
        while(i<a-1){
           first= first->next;
            i++;
        }
        ListNode* tempFirst = first->next;
        // set first->next as second;
        first->next= second;
                
//         // set second at its tail 
        while(second->next!=nullptr){
            second= second->next;
        }
        
        // set tempFirst at (b+1)th place 
        i=a;
        while(i<=b){
            tempFirst= tempFirst->next;
            i++;
        }
                
        // set second->next= tempFirst;
        second->next= tempFirst;
        
        return list1;
    }
};