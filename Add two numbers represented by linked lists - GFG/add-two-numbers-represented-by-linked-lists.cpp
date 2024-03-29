//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
      struct Node* reverse( struct Node* head){
        if(head==NULL|| head->next==NULL){
            return head;
        }
         struct Node* curr= head;
         struct Node* prev= NULL;
        while(curr!=NULL){
             struct Node*temp= curr->next;
            curr->next= prev;
            prev=curr;
            curr= temp;
        }
        return prev;
    }
     struct Node* sum( struct Node* first,  struct Node* second){
        if(first==NULL && second==NULL){
            return NULL;
        }
        if(first==NULL){
            return second;
        }
        if(second==NULL){
            return first;
        }
         struct Node* ans= new  struct Node(-1);
         struct Node* temp= ans;
        int carry=0;
        while(first!=NULL && second!=NULL){
         int sum  = first->data + second->data + carry;
              carry= sum/10;
               sum%=10;
             struct Node* newNode= new  struct Node(sum);
            temp->next= newNode;
            temp= newNode;
            first=first->next;
            second= second->next;
        }
        while(first!=NULL){
            int sum= first->data + carry;
            carry= sum/10;
            sum%=10;
             struct Node* newNode= new Node(sum);
            temp->next= newNode;
            temp= temp->next;
            first= first->next;
        }
         while(second!=NULL){
           int sum= second->data + carry;
            carry= sum/10;
            sum%=10;
            struct Node* newNode= new Node(sum);
            temp->next= newNode;
            temp= temp->next;
            second= second->next;
        }
        if(carry){
            struct Node* node =new  Node(carry);
            temp->next= node;
            temp= node;
        }

        return ans->next;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
         struct Node* revfirst = reverse(first);
         struct Node* revsecond= reverse(second);
         struct Node* res= sum(revfirst, revsecond);
        res = reverse(res);
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends