//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
   int solveRec(string str, string revStr, int i, int j){
      if(i==str.length() || j==revStr.length()) return 0;
        
        if(str[i]==revStr[j]) return 1 + solveRec(str, revStr, i+1, j+1);
        else{
            return max(solveRec(str, revStr, i+1, j), solveRec(str, revStr, i, j+1));
        }
    }
    int solveMem(string str, string revStr, int i, int j, vector<vector<int>>&dp){
        if(i==str.length() || j==revStr.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(str[i]==revStr[j]){
            ans= 1+solveMem(str, revStr, i+1, j+1, dp);
        }
        else{
            ans= max(solveMem(str, revStr, i+1, j, dp), solveMem(str, revStr, i, j+1, dp));
        }
        return dp[i][j]=ans;
    }
    int solveTab(string str, string revStr){
         vector<vector<int>>dp(str.length()+1, vector<int>(revStr.length()+1, 0));
        int ans=0;
         for(int i= str.length()-1; i>=0; i--){
             for(int j= revStr.length()-1; j>=0; j--){
                 if(str[i]==revStr[j]){
                     ans = 1 + dp[i+1][j+1];
                 }
                 else{
                     ans= max(dp[i+1][j], dp[i][j+1]);
                 }
                 dp[i][j]=ans;
             }
         }
        return dp[0][0];
    }
    int solveSpOpt(string str, string revStr){
        // i-> curr, i+1->next  so make vector of revStr length 
       vector<int>curr(revStr.length()+1, 0);
        vector<int>next(revStr.length()+1, 0);
        int ans=0;
         for(int i= str.length()-1; i>=0; i--){
             for(int j= revStr.length()-1; j>=0; j--){
                 if(str[i]==revStr[j]){
                     ans = 1 + next[j+1];
                 }
                 else{
                     ans= max(next[j], curr[j+1]);
                 }
                 curr[j]=ans;
             }
             next=curr;
         }
        return next[0];
    }
    int longestPalinSubseq(string str) {
        //code here
        string temp=str;
        reverse(str.begin(), str.end());
        string revStr= str;
        str= temp;
        // // // Approach-1> Using Recursion
        // return solveRec(str, revStr, 0, 0);

        // // // // Approach-2> Using Recursion + Meemoization
        // vector<vector<int>>dp(str.length(), vector<int>(revStr.length(), -1));
        // return solveMem(str, revStr, 0, 0, dp);
       

        // //  // Approach-3> Using Tabulation(Bottom up)
        return solveTab(str, revStr);

           // Approach-4> Using Tabulation(Bottom up)+Space optimization
        return solveSpOpt(str, revStr);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends