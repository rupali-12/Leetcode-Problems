class Solution {
public:
    int solveRec(int n){
        if(n==0 || n==1) return 1;
        
        int ans=0;
        for(int i=1; i<=n; i++){
            ans+= solveRec(i-1)*solveRec(n-i);
        }
        return ans;
    }
    int solveMem(int n, vector<int>&dp){
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;
        for(int i=1; i<=n; i++){
            ans+= solveMem(i-1, dp)*solveMem(n-i, dp);
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        // // Approach-1: Recursion 
        // return solveRec(n);
        
         // Approach-2: Memoization
        vector<int>dp(n+1, -1);
        return solveMem(n, dp);
    }
};