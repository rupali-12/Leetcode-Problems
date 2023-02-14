//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include<vector>
class Solution{
    private:
    // Node* revrse(Node* &head){
    //     Node* prev= NULL;
    //     Node* temp= head;
    //     while(temp!=NULL){
    //          Node* forward= temp->next;
    //         temp->next = prev;
    //         prev=temp;
    //         temp=forward;
    //     }
      
    //     return prev;
    // }
    
    
//     Node* revers(Node* &head){
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//      Node *temp = revers(head->next);
//     head->next->next= head;
//     head->next= NULL;
//     return temp;
// }


bool checkPalindrome(vector<int>v){
    int n= v.size();
    int s=0, e=n-1;
    while(s<=e){
        if(v[s]!=v[e]){
            return false;
        }
        s++; e--;
    }
    return true;
}
  public:
    //Function to check whether the list is palindrome.
    
    bool isPalindrome(Node *head)
    {
        //Your code here
    //  Approach --1>. By creating an array >>>>>>>>>>>>>>>>>   
        vector<int>v;
        Node* temp= head;
        while(temp!=NULL){
            v.push_back(temp->data);
            temp= temp->next;
        }
        if(checkPalindrome(v)){
            return true;
        }
        else{
            return false;
        }
        
        
    //     if(head== NULL || head->next==NULL){
    //         return true;
    //     }
    //     Node* temp = head;
    //     Node* ans =revers(head);
    //     if(temp==ans){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends