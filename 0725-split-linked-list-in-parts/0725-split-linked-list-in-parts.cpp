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
        int len=0;
        while(temp!=NULL){
            len++;
            temp= temp->next;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k, NULL);
        if(head==NULL) return ans;
        
        int length = findLength(head);
        int exCount= length%k;
        
        ListNode* curr= head;
          ListNode* prev= NULL;
         
        for(int i=0; i<k; i++){
            ans[i]=curr;
            
            for(int count=1; count<= ((length/k) + (exCount>0?1:0 )); count++){
                prev= curr;
                curr= curr->next;
            }
            prev->next= NULL;
            exCount--;   // reduce if exist 
        }
        return ans;
    }
};