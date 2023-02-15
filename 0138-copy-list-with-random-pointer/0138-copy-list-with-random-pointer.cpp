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
    private:
     void insertAtTail(Node* &cloneHead, Node* &cloneTail, int d){
        Node* temp= new Node(d);
        if(cloneHead==NULL){
            cloneHead = temp;
            cloneTail = temp;
        }
        else{
            cloneTail->next= temp;
            cloneTail= temp;
        }
    }
public:
    Node* copyRandomList(Node* head) {
            Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp= temp->next;
        }
        // Mapping of original nodes with the cloned node 
        Node* originalNode= head;
        Node* cloneNode= cloneHead;
        map<Node*, Node*>mp;
        while(originalNode!=NULL){
            mp[originalNode]=cloneNode;
            originalNode= originalNode->next;
            cloneNode= cloneNode->next;
        }
        
        // point random pointers of cloned node 
        originalNode= head;
        cloneNode= cloneHead;
        while(originalNode!=NULL){
            cloneNode->random = mp[originalNode->random];
            originalNode= originalNode->next;
            cloneNode= cloneNode->next;
        }
       return cloneHead;
    }
};