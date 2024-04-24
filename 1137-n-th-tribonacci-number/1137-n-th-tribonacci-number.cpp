class Solution {
public:
    int solveRec(int n){
        if(n==0) return 0;
        else if(n==1 || n==2) return 1;
        return solveRec(n-1)+ solveRec(n-2) + solveRec(n-3);
    }
    
     int solveMem(int n, int *dp){
        if(n==0) return dp[n]=0;
        else if(n==1 || n==2) return dp[n]= 1;
         if(dp[n]!=-1) return dp[n];
        return dp[n] = solveMem(n-1, dp)+ solveMem(n-2, dp) + solveMem(n-3, dp);
    }
    
    int tribonacci(int n) {
        // // Approach-1: Recursion 
        // return solveRec(n);
        
        // Approach-2: Memoization + Recursion
        int dp[38];
        fill(dp, dp+38, -1);
        return solveMem(n, dp);
    }
};