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
    ListNode* mergeSortedList(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val <= l2->val){
            l1->next = mergeSortedList(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeSortedList(l1, l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* partitionAndMerge(int s, int e, vector<ListNode*> lists){
        if(s>e) return NULL;
        if(s==e){
            return lists[s];
        }
        int mid = s + (e-s)/2;
        ListNode* l1 = partitionAndMerge(s, mid, lists);
        ListNode* l2 = partitionAndMerge(mid+1, e, lists);

        return mergeSortedList(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        // Approach -1: using partition
        int n = lists.size();
        if(n==0) return NULL;
        return partitionAndMerge(0, n-1, lists);
    }
};