class Solution {
public:
    int solveRec(vector<int>& values, int i, int j){
        if(i+1==j){
            return 0;
        }
        int ans = INT_MAX;
    for(int k=i+1; k<=j-1; k++){
   int sum =(values[i]*values[k]*values[j]) + solveRec(values, i, k) + solveRec(values, k, j);
           ans =min(ans, sum);
        }
        return ans;
    }
    
     int solveMem(vector<int>& values, int i, int j,  vector<vector<int>>&dp){
        if(i+1==j){
            return 0;
        }
         if(dp[i][j]!=-1){
             return dp[i][j];
         }
        int ans = INT_MAX;
    for(int k=i+1; k<=j-1; k++){
   int sum =(values[i]*values[k]*values[j]) + solveMem(values, i, k, dp) + solveMem(values, k, j, dp);
           ans =min(ans, sum);
        dp[i][j]=ans;
        }
         return ans;
        // return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        
        // // Approach->1 using Recursion 
        // return solveRec(values, 0, values.size()-1);
        
         // Approach->2 using Recursion + Memoization
        int n= values.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solveMem(values, 0, n-1, dp);
    }
};