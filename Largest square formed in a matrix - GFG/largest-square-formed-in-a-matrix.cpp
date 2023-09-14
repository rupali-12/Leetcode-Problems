//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int solveRec(vector<vector<int>>&mat, int i, int j, int &maxAns){
       if(i>= mat.size() || j>= mat[0].size()){
           return 0;
       }
      
       int down= solveRec(mat, i+1, j, maxAns);
       int right= solveRec(mat, i, j+1, maxAns);
       int diag = solveRec(mat, i+1, j+1, maxAns);
       
      //   check curr element is 1 or not
      if(mat[i][j]==1){
           int ans= 1 + min(right, min(diag, down));
       maxAns = max(maxAns, ans);
           return ans;
      }
      else return 0;
   }
   int solveMem(vector<vector<int>>&mat, int i, int j, int &maxAns, vector<vector<int>> &dp){
       if(i>= mat.size() || j>= mat[0].size()){
           return 0;
       }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
       int down= solveMem(mat, i+1, j, maxAns, dp);
       int right= solveMem(mat, i, j+1, maxAns, dp);
       int diag = solveMem(mat, i+1, j+1, maxAns, dp);
       
      //   check curr element is 1 or not
      if(mat[i][j]==1){
           dp[i][j] = 1 + min(right, min(diag, down));
       maxAns = max(maxAns, dp[i][j]);
           return dp[i][j];
      }
      else return dp[i][j]= 0;
   }
   int solveTab(vector<vector<int>>mat, int &maxAns){
      vector<vector<int>>dp(mat.size()+1, vector<int>(mat[0].size()+1, 0));
       
      for(int i=mat.size()-1; i>=0; i--){
          for(int j= mat[0].size()-1; j>=0; j--){
        int down= dp[i+1][j];
      int right= dp[i][j+1];
      int diag = dp[i+1][j+1];
       
      //   check curr element is 1 or not
      if(mat[i][j]==1){
          dp[i][j] = 1 + min(right, min(diag, down));
      maxAns = max(maxAns, dp[i][j]);
      }
      else {
          dp[i][j]= 0;
      }
          }
      }
      return dp[0][0];
   }
    int solveSpOpt1(vector<vector<int>>mat, int &maxAns){
     vector<int>curr(mat[0].size()+1, 0);
     vector<int>next(mat[0].size()+1, 0);
       
      for(int i=mat.size()-1; i>=0; i--){
          for(int j= mat[0].size()-1; j>=0; j--){
        int down=next[j];
      int right= curr[j+1];
      int diag = next[j+1];
       
      //   check curr element is 1 or not
      if(mat[i][j]==1){
          curr[j] = 1 + min(right, min(diag, down));
      maxAns = max(maxAns, curr[j]);
      }
      else {
          curr[j]= 0;
      }
          }
          next= curr;
      }
      return next[0];
   }
    int solveSpOpt2(vector<vector<int>>mat, int &maxAns){
       int row=mat.size();
       int col= mat[0].size();
      for(int i=row-1; i>=0; i--){
          for(int j= col-1; j>=0; j--){
        int down=(i<row-1)?mat[i+1][j]:0;
      int right= (j<col-1)?mat[i][j+1]:0;
      int diag = (j<col-1 && i<row-1)?mat[i+1][j+1]:0;
       
      //   check curr element is 1 or not
      if(mat[i][j]==1){
          mat[i][j] = 1 + min(right, min(diag, down));
      maxAns = max(maxAns, mat[i][j]);
      }
      else {
          mat[i][j]= 0;
      }
          }
      }
   }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        // // Approach-1: Recursion 
        // int maxAns=0;
        // solveRec(mat, 0, 0, maxAns);
        // return maxAns;
        
        // // Approach-2: Memoization 
        // int maxAns=0;
        // vector<vector<int>>dp(mat.size(), vector<int>(mat[0].size(), -1));
        // solveMem(mat, 0, 0, maxAns, dp);
        // return maxAns;
        
        // // Approach-3: Tabulation 
        // int maxAns=0;
        // solveTab(mat, maxAns);
        // return maxAns;
        
        // //   Approach-4: Tabulation +  space optimization 1 (using two vectors 
        // int maxAns=0;
        // solveSpOpt1(mat, maxAns);
        // return maxAns;
        
        //   Approach-5: Tabulation +  space optimization 2 [SC-O(1)]
        int maxAns=0;
        solveSpOpt2(mat, maxAns);
        return maxAns;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends