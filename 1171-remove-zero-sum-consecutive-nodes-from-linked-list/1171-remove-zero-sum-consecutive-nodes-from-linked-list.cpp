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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            if(head->val==0) return NULL;
            else return head;
        }
        unordered_map<int, ListNode*>mp;
        ListNode* dummynode = new ListNode(0);
       
        dummynode->next= head;
         mp[0]= dummynode;
        int prefixSum=0;
        while(head!=NULL){
            prefixSum+= head->val;
            
            // deletion 0 sum nodes 
            if(mp.find(prefixSum)!=mp.end()){
               ListNode* start= mp[prefixSum];
                ListNode* temp= start;
                int psum=prefixSum;
                while(temp!=head){
                    temp= temp->next;
                    psum+= temp->val;
                    
                    if(temp!=head){
                        mp.erase(psum);
                    }
                }
                start->next= head->next;   // here head=temp, so temp->next also work
            }
            else{
                mp[prefixSum] = head;
            }
            head= head->next;
        }
       return dummynode->next;
    }
};