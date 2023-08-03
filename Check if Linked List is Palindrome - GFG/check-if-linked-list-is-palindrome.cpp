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
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    //Function to check whether the list is palindrome.
    // Approach-1> 
    // bool isPalin(vector<int>arr){
    //     int i=0, j=arr.size()-1;
    //     while(i<=j){
    //         if(arr[i]!=arr[j]){
    //             return false;
    //         }
    //         i++; j--;
    //     }
    //     return true;
    // }
    
     // Approach-2->>
    int getLength(Node*head){
        int count=0;
        Node* temp= head;
        while(temp!=NULL){
            count++;
            temp= temp->next;
        }
        return count;
    }
    Node* findMid(Node* head, int count){
        int len=0;
        Node* temp=head;
        while(len<count/2){
            temp= temp->next;
            len++;
        }
        return temp;
    }
    Node* reverse(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        auto ans= reverse(head->next);
        head->next->next= head;
        head->next=NULL;
        return ans;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        // // Approach-1> using array
        // vector<int>arr;
        // Node* temp= head;
        // while(temp!=NULL){
        //     arr.push_back(temp->data);
        //     temp= temp->next;
        // }
        // return isPalin(arr);
        
          // Approach-> 2->Find mid , Revrse after mid and compare the two halves
        int length= getLength(head);
        Node* mid= findMid(head, length);
        Node* revList =reverse(mid);
        Node* rev= revList;
        Node* temp= head;
        
        while(temp!=mid && rev!=NULL){
            if(rev->data!= temp->data){
                return false;
            }
            rev= rev->next;
            temp= temp->next;
        }
        
        return true;
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