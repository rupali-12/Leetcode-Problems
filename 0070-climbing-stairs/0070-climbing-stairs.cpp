class Solution {
public:
    int solveRec(int n, int step){
        if(n==0 || n==1 || step==n){
            return 1;
        }
        if(step>n) return 0;
        int take1 = solveRec(n, step+1);
        int take2 = solveRec(n, step+2);
        return take1 + take2;
    }
     int solveMem(int n, int step, vector<int>&dp){
        if(n==0 || n==1 || step==n){
            return 1;
        }
         if(step>n) return 0;
         if(dp[step]!=-1){
             return dp[step];
         }
        int take1 = solveMem(n, step+1, dp);
        int take2 = solveMem(n, step+2, dp);
        return dp[step] = take1 + take2;
    }
    int solveTab(int n, vector<int>&dp){
        dp[0]=dp[1]=1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
      // // Approach-1: Recursion 
      //   return solveRec(n, 0);
        
     // // Approach-2: Recursion + Memoization
        vector<int>dp(n+1, -1);
        return solveMem(n, 0, dp);
        
        // // Approach- 3 Tabulation 
        // vector<int>dp(n+1, 0);
        // return solveTab(n, dp);
    }
};