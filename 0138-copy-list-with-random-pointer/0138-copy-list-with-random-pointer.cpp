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
      void insertAtTail(Node* &cloneHead, Node* &cloneTail, int data){
        Node* temp= new Node(data);
        
        if(cloneHead==NULL){
            cloneHead = temp;
            cloneTail= temp;
        }
        else{
            cloneTail->next=temp;
            cloneTail = temp;
        }
        return; 
    }
    
//     // Approach-1: Using unordered map TC=O(N), SC= O(N)
    Node* copyRandomList(Node* head) {
        Node* cloneHead =NULL;
        Node* cloneTail= NULL;
        Node* temp= head;
        
        while(temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp= temp->next;
        }
        
        // map original node with clone list 
        unordered_map<Node* , Node*>mp;
        Node* cloneNode = cloneHead;
        Node* originalNode = head;
        
        while(originalNode!=NULL){
            mp[originalNode]= cloneNode;
            originalNode= originalNode->next;
            cloneNode= cloneNode->next;
        }
       
        
        // copy random pointers 
          cloneNode = cloneHead;
          originalNode = head;
        while(originalNode!=NULL){
            cloneNode->random = mp[originalNode->random];
            originalNode= originalNode->next;
            cloneNode= cloneNode->next;
        }
        return cloneHead;
    }
    
};