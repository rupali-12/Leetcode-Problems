/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Approach-1 

        if(head==NULL) return NULL;
        unordered_map<Node*, Node*>mp;
        Node* curr= head;
        Node* prev= NULL;
        Node* newHead=NULL;

        while(curr!=NULL){
            Node* temp=new Node(curr->val);
           
           mp[curr] =temp;  //storing
            
            if(newHead==NULL){   // Initialize
               newHead = temp;
               prev = newHead;
            }
            else{
                prev->next= temp;
                prev= temp;
            }

            curr= curr->next;
        }

        // Now set random pointers
        curr=head;
        Node* newCurr =newHead;
        while(curr!=NULL){
            if(curr->random==NULL){
                newCurr->random =NULL;
            }
            else{
                newCurr->random = mp[curr->random];
            }
            curr= curr->next;
            newCurr= newCurr->next;
        }
        return newHead;
    }
};