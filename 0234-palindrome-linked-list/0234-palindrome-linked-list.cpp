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
    // Approach-1
    //  bool isPalin(vector<int>arr){
    //     int i=0, j=arr.size()-1;
    //     while(i<=j){
    //         if(arr[i]!=arr[j]){
    //             return false;
    //         }
    //         i++; j--;
    //     }
    //     return true;
    // }
    
    // Approach-2
    int getLength(ListNode*head){
        int count=0;
        ListNode* temp= head;
        while(temp!=NULL){
            count++;
            temp= temp->next;
        }
        return count;
    }
    ListNode* findMid(ListNode* head, int count){
        int len=0;
        ListNode* temp=head;
        while(len<count/2){
            temp= temp->next;
            len++;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        auto ans= reverse(head->next);
        head->next->next= head;
        head->next=NULL;
        return ans;
    }
    bool isPalindrome(ListNode* head) {
        //   // Approach-1> using array
        // vector<int>arr;
        // ListNode* temp= head;
        // while(temp!=NULL){
        //     arr.push_back(temp->val);
        //     temp= temp->next;
        // }
        // return isPalin(arr);
        
        // Approach-> 2->Find mid , Revrse after mid and compare the two halves
        int length= getLength(head);
        ListNode* mid= findMid(head, length);
        ListNode* revList =reverse(mid);
        ListNode* rev= revList;
        ListNode* temp= head;
        
        while(temp!=mid && rev!=NULL){
            if(rev->val!= temp->val){
                return false;
            }
            rev= rev->next;
            temp= temp->next;
        }
        
        return true;
    }
};