//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
      int solveRec(int eggs,int floors){
        if(floors==0 || floors==1) return floors;
        if(eggs== 1) return floors;
        int ans= INT_MAX;
        for(int k= 1; k<=floors; k++){
            // max is bcoz to find worst case thn find min sttempts in worst case 
            int temp= 1 + max(solveRec(eggs-1, k-1), solveRec(eggs, floors-k));   
            ans= min(ans, temp);
        }
        return ans;
    }
    
      int solveMem(int eggs,int floors,vector<vector<int>>&dp){
        if(floors==0 || floors==1) return floors;
        if(eggs== 1) return floors;
          
          if(dp[eggs][floors]!=-1){
              return dp[eggs][floors];
          }
        int ans= INT_MAX;
        for(int k= 1; k<=floors; k++){
            // max is bcoz to find worst case thn find min sttempts in worst case 
            int temp= 1 + max(solveMem(eggs-1, k-1, dp), solveMem(eggs, floors-k, dp));   
            ans= min(ans, temp);
        }
        return dp[eggs][floors]= ans;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
         // n- number of eggs 
        // k- floors 
        
        // // Approach 1: Recursion
        // return solveRec(n, k);
        
        //  // Approach 2: Recursion + memoization 
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        return solveMem(n, k, dp);
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends