//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solveRec(int *a, int n, int currIndex, int prevIndex){
        if(currIndex==n){
            return 0;
        }
        // prevIndex  currIndex
        // case of include-> include only when it is first element or then element shoud be greater than element at prevIndex
      int include=0;
        if(prevIndex==-1 || a[currIndex]>a[prevIndex]){
         include = 1 + solveRec(a, n, currIndex+1, currIndex);
        }
         
        //  exclude
         int exclude = 0 + solveRec(a, n, currIndex+1, prevIndex);
         return max(include, exclude);
    }
        int solveMem(int *a, int n, int currIndex, int prevIndex,vector<vector<int>>&dp){
        if(currIndex==n){
            return 0;
        }
        if(dp[currIndex][prevIndex+1]!=-1){
            return dp[currIndex][prevIndex+1];
        }
          int include=0;
        if(prevIndex==-1 || a[currIndex]>a[prevIndex]){
         include = 1 + solveMem(a, n, currIndex+1, currIndex, dp);
        }
         
        //  exclude
         int exclude = 0 + solveMem(a, n, currIndex+1, prevIndex,dp);
         return dp[currIndex][prevIndex+1]= max(include, exclude);   // to avoid negative index
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
    //   Approach-1>> brute force 
    
    // // Approach-2>>Using Recursion 
    // return solveRec(a, n, 0, -1);
    
     // Approach-2>>Using Recursion + memoization
     vector<vector<int>>dp(n , vector<int>(n+1, -1));
    return solveMem(a, n, 0, -1, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends