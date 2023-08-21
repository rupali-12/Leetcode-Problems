class Solution {
public:
    int solveRec(int n){
        if(n==0 || n==1){
            return 1;
        }
        int ans=0;
       for(int i=1; i<=n; i++){
           ans+= solveRec(i-1)*solveRec(n-i);
       }
        return ans;
    }
    int solveMem(int n, vector<int>&dp){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans =0;
        for(int i=1; i<=n; i++){
            ans+= solveMem(i-1, dp) *solveMem(n-i, dp);
        }
        return dp[n]=ans;
    }
    int solveTab(int n){
        vector<int>dp(n+1, 0);
        dp[0]=1;
        dp[1]=1;
      for(int i=2; i<=n; i++){
          for(int j=1; j<=i; j++){
              dp[i]+= dp[j-1]* dp[i-j];
          }
      }
        return dp[n];
    }

//       int solveSpOpt(int n){
//         if(n<=1){
//             return 1;
//         }
//           int ans=0;
//           // int ans=1;
//         for(int i=0; i<n; i++){
//             ans+= solveSpOpt(i)*solveSpOpt(n-i-1);
//               // ans = ans *2*(2*i+1)/(i+2);  // overfow
//         }
//         return ans;
//     }
    int numTrees(int n) {
        
        // // Approach 1>> Using Recursion 
        // return solveRec(n);
        
        // // Approach 2>> Using Recursion+MEmoization  
        // vector<int>dp(n+1, -1);
        // return solveMem(n, dp);
        
        //  // Approach 3>> Using Tabulation  
        return solveTab(n);
        
          // Approach 34> Using space optimization  
        // return solveSpOpt(n);
    }
};