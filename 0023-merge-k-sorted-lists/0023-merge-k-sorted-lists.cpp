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
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
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
        // Approach-1: MAnual processing merging one by one
    //     if(lists.empty()) return NULL;
    //    ListNode* ans= lists[0];
    //     int i=1;

    //     while(i<lists.size()){
    //         ans = merge(ans, lists[i]);
    //         i++;
    //     }
    //     return ans;

    // Approach 2: using priority queue
     int k=lists.size();
     priority_queue<ListNode*, vector<ListNode*>, compare>minHeap;

     if(k==0) return NULL;

     for(int i=0; i<k; i++){
        if(lists[i]!=NULL){
            minHeap.push(lists[i]);
        }
     }

     ListNode* head= NULL;
     ListNode* tail= NULL;

     while(minHeap.size()>0){
       ListNode* top =minHeap.top();
       minHeap.pop();

       if(top->next != NULL){  // insert in heap
            minHeap.push(top->next);
          }

       if(head==NULL){   // first insertion
          head= top;
          tail=top;
       }
       else{
          tail->next= top;
          tail =top;
       }
     }

     return head;
    }
};