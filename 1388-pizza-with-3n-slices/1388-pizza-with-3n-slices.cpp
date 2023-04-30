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
    int solveTab(vector<int>&slices){
        // here n is total number of slices, and k is the number of slices per person 
         int n =slices.size();
        vector<vector<int>>dp1(n+2, vector<int>(n, 0));
         vector<vector<int>>dp2(n+2, vector<int>(n, 0));
        
        // case of include 1st slice
        for(int index=n-2; index>=0; index--){
            for(int k=1; k<=n/3; k++){
                int include =slices[index] + dp1[index+2][k-1];
                int exclude = 0 + dp1[index+1][k];
                dp1[index][k] = max(include, exclude);
            }
        }
        int case1 =dp1[0][n/3];  // want n/3 slices per person 
         // case of not include 1st slice
        for(int index=n-1; index>=1; index--){
            for(int k=1; k<=n/3; k++){
                int include =slices[index] + dp2[index+2][k-1];
                int exclude = 0 + dp2[index+1][k];
                dp2[index][k] = max(include, exclude);
            }
        }
        int case2 = dp2[1][n/3];
        return max(case1, case2);
    }
    int maxSizeSlices(vector<int>& slices) {
       // // Approach-1>> Using Recursion 
       //   int k =slices.size();
       //  int case1Taken =solveRec(0,k-2, slices, k/3);
       //  int case2NotTaken =solveRec(1, k-1, slices, k/3);
       //  return max(case1Taken, case2NotTaken);
        
        //  // Approach-2>> Using Recursion + Memoization
        //  int k =slices.size();
        // vector<vector<int>>dp1(k, vector<int>(k, -1));
        // int case1Taken =solveMem(0,k-2, slices, k/3, dp1);
        //  vector<vector<int>>dp2(k, vector<int>(k, -1));
        // int case2NotTaken =solveMem(1, k-1, slices, k/3, dp2);
        // return max(case1Taken, case2NotTaken);
        
         // Approach-3>> Using Tabulation
        return solveTab(slices);
    }
};