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
    ListNode* removeNodes(ListNode* head) {
        ListNode* dummy= new ListNode(INT_MAX);
        stack<ListNode*>s;
        s.push(dummy);
        while(head){
            while(s.top()->val < head->val){
                s.pop();
            }
            s.top()->next = head;
            s.push(head);
            head= head->next;
        }
        return dummy->next;
    }
};