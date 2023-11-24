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
    class compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
    ListNode* merge(ListNode* first, ListNode* second){
        if(first==NULL){
            return second;
        }
        if(second==NULL){
            return first;
        }
        
        ListNode* ans = new ListNode(-1);
        ListNode* temp =ans;
        
        while(first!=NULL && second!=NULL){
            if(first->val < second->val){
                temp->next= first;
                temp= first;
                first= first->next;
            }
            else{
                  temp->next= second;
                temp= second;
                second= second->next;
            }
        }
        
        while(first!=NULL){
             temp->next= first;
                temp= first;
                first= first->next;
        }
        while(second!=NULL){
              temp->next= second;
                temp= second;
                second= second->next;
        }
        ans= ans->next;
        return ans;
    }
    ListNode* mergeKLists(vector<ListNode*>& listArray) {
        // if(lists.empty()){
        //     return NULL;
        // }
        // ListNode* ans = lists[0];
        // int i=1;
        // while(i<lists.size()){
        //   ans = merge(ans, lists[i]);
        //     i++;
        // }
        // return ans;
        
        
        // **********************************************
        // Approach-2:
        priority_queue<ListNode*, vector<ListNode*>, compare>minheap;

    int k= listArray.size();
    // insert head of all lists 
    for(int i=0; i<k; i++){
         if(listArray[i]!=NULL){
             minheap.push(listArray[i]);
         }
    }
    
   ListNode* head=NULL, *tail=NULL;

    while(!minheap.empty()){
        ListNode* top = minheap.top();
        minheap.pop();

        if(head==NULL){
            head=tail= top;
        }
        else{
            tail->next= top;
            tail= top;
        }

        if(top->next!=NULL){
            minheap.push(top->next);
        }
    }
    return head;
    }
};