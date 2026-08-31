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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Approach -1: Brute force
        vector<int>arr;
        ListNode* temp= head;
        while(temp!=NULL){
          arr.push_back(temp->val);
          temp = temp->next;
        } 

        int n = arr.size();
        if(n<3) return {-1, -1};

        int mxDistance = maxDistance
    }
};