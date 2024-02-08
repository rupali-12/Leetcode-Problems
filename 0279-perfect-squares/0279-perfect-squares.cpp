class Solution {
public:
    int solveRec(int n){
        if(n==0) return 0;
        int ans=n;
        for(int i=1; i*i<=n; i++){
            ans= min(ans, 1 + solveRec(n-i*i));
        }
        return ans;
    }
     int solveMem(int n, vector<int>&dp){
        if(n==0) return 0;
         if(dp[n]!=-1) return dp[n];
        int ans=n;
        for(int i=1; i*i<=n; i++){
            ans= min(ans, 1 + solveMem(n-i*i, dp));
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        // // Approach-1: Recursion 
        // return solveRec(n);
        
         // Approach-2: Recursion + Memoization
        vector<int>dp(n+1, -1);
        return solveMem(n, dp);
    }
};