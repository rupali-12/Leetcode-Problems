//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends


//function Template for C++

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    // add code here
    
    // Approach--1>>using stack>>>>>>>>>>>>>>>>>>>>
    stack<int>s;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        s.push(temp);
    }
    
    queue<int>ans;
    while(!s.empty()){
        int temp= s.top();
        s.pop(); 
        ans.push(temp);
    }
    return ans;
    
    // *******************************************************************************************
    // Approach--2>>>using recursion>>>>>>>>>>>>>>>>>>>>>>
//     //   queue<int>ans;
//     if(q.empty()){
//         return q;
//     }
//      int temp= q.front();
//      q.pop();
//   q= rev(q);
//      q.push(temp);
     
//      return q;
}

