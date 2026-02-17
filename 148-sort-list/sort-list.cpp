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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        // split the listinto halves 
        ListNode* mid = getMid(head);
        ListNode* list1 = sortList(head);  //get first half
        ListNode* list2 = sortList(mid);  //get second half
       
    //    merge the splitted halves
        return merge(list1, list2);
    }

    // find mid 
    ListNode* getMid(ListNode* head){
        ListNode* prev =NULL;
        while(head!=NULL && head->next !=NULL){
            prev = (prev == NULL)? head: prev->next;
            head = head->next->next;
        }

        ListNode* mid = prev->next;
        prev->next = NULL;  //split the list into two halves
        return mid;
    }

    // merge splitted lists 
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(list1!=NULL && list2!=NULL){
            if(list1->val < list2->val){
                tail->next = list1;
                list1=list1->next;
            }
            else{
                tail->next = list2;
                list2=list2->next;
            }
            tail = tail->next;
        }

        // append the rem node of list1 or list2
        tail->next  = (list1!=NULL)? list1: list2;
        return dummy->next;
    }
};