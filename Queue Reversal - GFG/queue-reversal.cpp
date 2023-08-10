//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    // TLE 
    // void solve(queue<int>q, queue<int>&ans){
    //      if(q.empty()){
    //         return;
    //     }
    //     int temp= q.front();
    //     q.pop();
    //     solve(q, ans);
    //     ans.push(temp);
    // }

    // queue<int> rev(queue<int> q)
    // {
    //     // add code here.
    //  queue<int>ans;
    //  solve(q, ans);
    //   return ans;
    // }
    
    // Approach-2 using stack 
      queue<int> rev(queue<int> q)
    {
        // add code here.
     stack<int>temp;
    while(!q.empty()){
        temp.push(q.front());
        q.pop();
    }
    
    while(!temp.empty()){
        q.push(temp.top());
        temp.pop();
    }
      return q;
    }
    
};


//{ Driver Code Starts.
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
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends