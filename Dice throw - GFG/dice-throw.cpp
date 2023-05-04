//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long solveRec(int dice, int faces, int target){
      if(target<0){
          return 0;
      }
      if((dice==0 && target!=0) || (target==0 && dice!=0)){
          return 0;
      }
    //   if(dice==0 && target!=0){
    //       return 0;
    //   }
    //   if(target==0 && dice!=0){
    //       return 0;
    //   }
      
      if(dice==0 && target==0){
          return 1;
      }
      long long ans=0;
      for(int i=1; i<=faces; i++){
          ans = ans + solveRec(dice-1, faces, target-i);
      }
      return ans;
  }
  
  long long solveMem(int dice, int faces, int target, vector<vector<long long >>&dp){
      if(target<0){
          return 0;
      }
     if((dice==0 && target!=0) || (target==0 && dice!=0)){
          return 0;
     }
      if(dice==0 && target==0){
          return 1;
      }
      if(dp[dice][target]!=-1){
          return dp[dice][target];
      }
      long long ans=0;
      for(int i=1; i<=faces; i++){
          ans =ans + solveMem(dice-1, faces, target-i, dp);
      }
      dp[dice][target] =ans;
      
  }
    long long noOfWays(int M , int N , int X) {
        // code here
    //     // Approach-1: Using Recursion
    //   return solveRec(N, M, X);
    
  // Approach-1: Using Recursion+Memoi
  vector<vector<long long >>dp(N+1, vector<long long >(X+1, -1));
      return solveMem(N, M, X, dp);

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends