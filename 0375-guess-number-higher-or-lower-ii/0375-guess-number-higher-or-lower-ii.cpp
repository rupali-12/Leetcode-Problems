class Solution {
public:
    int solveRec(int start, int end){
        if(start>=end) return 0;
        int mini = INT_MAX;
        for(int i=start; i<=end; i++){
            mini= min(mini, i+max(solveRec(start, i-1), solveRec(i+1, end)));
        }
        return mini;
    }
      int solveMem(int start, int end,  vector<vector<int>>&dp){
        if(start>=end) return 0;
          if(dp[start][end]!=-1){
              return dp[start][end];
          }
        int mini = INT_MAX;
        for(int i=start; i<=end; i++){
            mini= min(mini, i+max(solveMem(start, i-1, dp), solveMem(i+1, end, dp)));
        }
        return dp[start][end] = mini;
    }
    int getMoneyAmount(int n) {
        // // Approach-1: Recursion 
        // // (start, end)
        // return solveRec(1, n);
        
         // Approach-2: Memoization 
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solveMem(1, n, dp);
    }
};