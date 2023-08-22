//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inorder(Node* root, vector<int>&inOrderVal){
    if(root==NULL){
        return;
    }
    inorder(root->left, inOrderVal);
    inOrderVal.push_back(root->data);
    inorder(root->right, inOrderVal);
    return;
}
vector<int>merge(vector<int>&inOrder1, vector<int>&inOrder2){
      vector<int>ans(inOrder1.size() + inOrder2.size());
      int i=0, j=0, k=0;
      while(i< inOrder1.size() && j<inOrder2.size()){
          if(inOrder1[i]<=inOrder2[j]){
              ans[k++]= inOrder1[i++];
          }
          else{
              ans[k++]= inOrder2[j++];
          }
      }
      while(i<inOrder1.size()){
          ans[k++]= inOrder1[i++];
      }
      while(j<inOrder2.size()){
          ans[k++]= inOrder2[j++];
      }
      return ans;
}
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
  vector<int>inOrder1;
    vector<int>inOrder2;
    inorder(root1, inOrder1);
    inorder(root2, inOrder2);

    // Merge two sorted array 
    vector<int>mergedArray = merge(inOrder1, inOrder2);
    return mergedArray;
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends