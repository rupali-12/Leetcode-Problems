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
    ListNode* merge(ListNode* first, ListNode* second){
        if(first==NULL) return second;
        if(second==NULL) return first;
        
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;
        while(first!=NULL && second !=NULL){
            if(first->val < second->val){
                temp->next = first;
                first= first->next;
            }
            else{
                temp->next = second;
                second= second->next;
            }
                temp=temp->next;
        }
        
        temp->next = first==NULL?second:first;
        return ans->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
       ListNode* ans= lists[0];
        int i=1;

        while(i<lists.size()){
            ans = merge(ans, lists[i]);
            i++;
        }
        return ans;
    }
};