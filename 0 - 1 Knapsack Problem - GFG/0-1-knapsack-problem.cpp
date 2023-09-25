//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int  solveRec(int wt[], int val[], int W, int n){
        if(n==0 || W==0) return 0;
        
        // include
        if(wt[n-1]<=W){
            return max(val[n-1] + solveRec(wt, val, W-wt[n-1], n-1), solveRec(wt, val, W, n-1));
        }
        else{
            return solveRec(wt, val, W, n-1);
        }
    }
    int  solveMem(int wt[], int val[], int W, int n, vector<vector<int>>&dp){
        if(n==0 || W==0) return 0;
        if(dp[n][W]!=-1){
            return dp[n][W];
        }
        int ans=0;
        // include
        if(wt[n-1]<=W){
            ans= max(val[n-1] + solveMem(wt, val, W-wt[n-1], n-1, dp), solveMem(wt, val, W, n-1, dp));
        }
        else{
            ans= solveMem(wt, val, W, n-1, dp);
        }
        return dp[n][W] =ans;
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
    // //   Approach-1: Recursion 
    // return solveRec(wt, val, W, n);
    
     //   Approach-1: Mamoization 
     vector<vector<int>>dp(n+1, vector<int>(W+1, -1));
    return solveMem(wt, val, W, n, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends