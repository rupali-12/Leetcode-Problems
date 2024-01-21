class Solution {
public:
    int mod =1e9 +7;
    int solveRec(int n){
        if(n==0) return 1;
        if(n==1) return 2;
        
        return (solveRec(n-1) + solveRec(n-2))%mod;
    }
     int solveMem(int n, vector<int>&dp){
        if(n==0) return 1;
        if(n==1) return 2;
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = (solveMem(n-1, dp) + solveMem(n-2, dp))%mod;
    }
    int solveTab(int n){
         vector<int>dp(n+1, 0);
        dp[0]=1; 
        dp[1] = 2;
        for(int i=2; i<=n; i++){
            dp[i] = (dp[i-1]+dp[i-2])%mod;
        }
        return dp[n];
    }
    int countHousePlacements(int n) {
        // // Approach-1: Recursion 
        // int ansOfOneSide = solveRec(n);
        // int ansOfTwoSide = ansOfOneSide*ansOfOneSide;
        // return ansOfTwoSide;
        
        //  // Approach-2: Recursion + Memoization
        // vector<int>dp(n+1, -1);
        // long long ansOfOneSide = solveMem(n, dp)%mod;
        // long long ansOfTwoSide = (ansOfOneSide*ansOfOneSide)%mod;
        // return ansOfTwoSide;
        
         // Approach-3: Tabualtion (bottom up)
        long long ansOfOneSide = solveTab(n)%mod;
        long long ansOfTwoSide = (ansOfOneSide*ansOfOneSide)%mod;
        return ansOfTwoSide;
    }
};