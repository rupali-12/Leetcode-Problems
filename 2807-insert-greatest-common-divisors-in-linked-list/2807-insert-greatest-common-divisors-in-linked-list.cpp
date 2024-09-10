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
    int findGcd(int a, int b){
        if(a==b) return a;
        if(a>b){
            return findGcd(a-b, b);
        }
        return findGcd(a, b-a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        vector<int>v;
        ListNode* temp= head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp= temp->next;
        }
        
        int n= v.size();
        vector<int>gcd(v.size()-1);
        for(int i=0; i<n-1; i++){
            int first= v[i];
            int second= v[i+1];
            int curr_gcd = findGcd(first, second);
            gcd[i] = curr_gcd;
        }
        
        ListNode* ans = new ListNode(0);
        temp=ans;
        for(int i=0; i<n-1; i++){
            // insert ith from v 
            ListNode* newNode1= new ListNode(v[i]);
            temp->next= newNode1;
            temp= temp->next;
            
             // insert ith from gcd
            ListNode* newNode2= new ListNode(gcd[i]);
            temp->next= newNode2;
            temp= temp->next;
        }
        
        // insert last node from v 
            ListNode* newNode= new ListNode(v[n-1]);
            temp->next= newNode;
            temp= temp->next;
        return ans->next;
    }
};