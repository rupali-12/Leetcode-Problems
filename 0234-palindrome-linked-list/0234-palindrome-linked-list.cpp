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
     bool isPalin(vector<int>arr){
        int i=0, j=arr.size()-1;
        while(i<=j){
            if(arr[i]!=arr[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
          // Approach-1> using array
        vector<int>arr;
        ListNode* temp= head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp= temp->next;
        }
        return isPalin(arr);
    }
};