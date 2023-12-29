class Solution {
public:
    int solveRec(vector<int>& jobDifficulty, int i, int d, int n){
       if(d==1){
           return *max_element(begin(jobDifficulty)+i, end(jobDifficulty));
       }
        
       int result=INT_MAX;
        int currMax= INT_MIN;
      for(int j=i; j<= (n-d); j++){
          currMax = max(currMax, jobDifficulty[j]);
          result= min(result, currMax+ solveRec(jobDifficulty, j+1, d-1, n));
      }
        return result;
    }
     int solveMem(vector<int>& jobDifficulty, int i, int d, int n, vector<vector<int>>&dp){
       if(d==1){
           return *max_element(begin(jobDifficulty)+i, end(jobDifficulty));
       }
        
         if(dp[i][d]!=-1){
             return dp[i][d];
         }
       int result=INT_MAX;
        int currMax= INT_MIN;
      for(int j=i; j<= (n-d); j++){
          currMax = max(currMax, jobDifficulty[j]);
          result= min(result, currMax+ solveMem(jobDifficulty, j+1, d-1, n, dp));
      }
        return dp[i][d]=result;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n) return -1;
        
//         // Approach-1: Recursion
//         return solveRec(jobDifficulty, 0, d, n);
        
        // Approach-2: Recursion + Memoization
        vector<vector<int>>dp(n, vector<int>(d+1, -1));
        return solveMem(jobDifficulty, 0, d, n, dp);
    }
};