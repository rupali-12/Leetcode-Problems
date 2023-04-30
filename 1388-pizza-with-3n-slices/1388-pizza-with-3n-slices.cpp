class Solution {
public:
    int solveRec(int index, int endIndex, vector<int>& slices, int n){
        if(n==0 || index>=endIndex){
            return 0;
        }
        int include = slices[index] + solveRec(index+2,endIndex, slices, n-1);
        int exclude = 0 + solveRec(index+1,endIndex, slices, n);
        return max(include, exclude);
    }
    int solveMem(int index, int endIndex, vector<int>& slices, int n, vector<vector<int>>&dp){
        if(n==0 || index>endIndex){
            return 0;
        }
        if(dp[index][n]!=-1){
            return dp[index][n];
        }
         int include = slices[index] + solveMem(index+2,endIndex, slices, n-1, dp);
        int exclude = 0 + solveMem(index+1,endIndex, slices, n, dp);
        return dp[index][n] =max(include, exclude);
    }
    int maxSizeSlices(vector<int>& slices) {
       // // Approach-1>> Using Recursion 
       //   int k =slices.size();
       //  int case1Taken =solveRec(0,k-2, slices, k/3);
       //  int case2NotTaken =solveRec(1, k-1, slices, k/3);
       //  return max(case1Taken, case2NotTaken);
        
         // Approach-2>> Using Recursion + Memoization
         int k =slices.size();
        vector<vector<int>>dp1(k, vector<int>(k, -1));
        int case1Taken =solveMem(0,k-2, slices, k/3, dp1);
         vector<vector<int>>dp2(k, vector<int>(k, -1));
        int case2NotTaken =solveMem(1, k-1, slices, k/3, dp2);
        return max(case1Taken, case2NotTaken);
    }
};