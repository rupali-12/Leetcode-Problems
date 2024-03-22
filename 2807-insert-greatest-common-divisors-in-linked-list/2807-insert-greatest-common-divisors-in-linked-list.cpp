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
    int findGCD(int a, int b){
        if(a==b) return a;
        else if(a>b){
            return findGCD(a-b, b);
        }
        else{
            return findGCD(a, b-a);
        }
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
        
        // fill gcd vector
        for(int i=0; i<n-1; i++){
            int first= v[i];
            int second= v[i+1];
            int curr_gcd = findGCD(first, second);
            gcd[i]= curr_gcd;
        }
        ListNode* ans= new ListNode(0);
       temp= ans;
        
        for(int i=0; i<n-1; i++){
        
            // insert ith from v  
            ListNode* newNode1= new ListNode(v[i]);
            temp->next= newNode1;
            temp= newNode1;
           
             // insert ith from gcd  
            ListNode* newNode2= new ListNode(gcd[i]);
            temp->next= newNode2;
            temp= newNode2;
        }
        
        // insert last value from vth 
        ListNode* newNode= new ListNode(v[n-1]);
        temp->next= newNode;
        temp= newNode;
        return ans->next;
    }
};