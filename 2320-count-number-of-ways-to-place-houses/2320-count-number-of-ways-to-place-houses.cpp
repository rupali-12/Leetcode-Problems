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
    int countHousePlacements(int n) {
        // // Approach-1: Recursion 
        // int ansOfOneSide = solveRec(n);
        // int ansOfTwoSide = ansOfOneSide*ansOfOneSide;
        // return ansOfTwoSide;
        
         // Approach-2: Recursion + Memoization
        vector<int>dp(n+1, -1);
        long long ansOfOneSide = solveMem(n, dp)%mod;
        long long ansOfTwoSide = (ansOfOneSide*ansOfOneSide)%mod;
        return ansOfTwoSide;
    }
};