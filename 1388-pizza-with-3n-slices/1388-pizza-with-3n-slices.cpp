class Solution {
public:
    int solveRec(int index, int endIndex, vector<int>& slices, int n){
       if(n==0 || index>endIndex) return 0;
        
        int take= slices[index] +solveRec(index+2, endIndex, slices, n-1);
         int nottake= 0 +solveRec(index+1, endIndex, slices, n);
        int ans = max(take, nottake);
        return ans;
    }
    int solveMem(int index, int endIndex, vector<int>& slices, int n, vector<vector<int>>&dp){
        if(n==0 || index>endIndex) return 0;
        if(dp[index][n]!=-1){
            return dp[index][n];
        }
        int take= slices[index] +solveMem(index+2, endIndex, slices, n-1, dp);
         int nottake= 0 +solveMem(index+1, endIndex, slices, n, dp);
        int ans = max(take, nottake);
        return dp[index][n]= ans;
    }
//     int solveTab(vector<int>&slices){
//         // here n is total number of slices, and k is the number of slices per person 
     
//         int case1 =dp1[0][n/3];  // want n/3 slices per person 
        
//         // case of not include 1st slice
        
//     }
//     int solveSpOpt(vector<int>&slices){
       
//     }
    int maxSizeSlices(vector<int>& slices) {
       // // // Approach-1>> Using Recursion 
       //   int k =slices.size();
       //  int case1Taken =solveRec(0, k-2, slices, k/3);
       //  int case2NotTaken =solveRec(1, k-1, slices, k/3);
       //  return max(case1Taken, case2NotTaken);
        
        //  // Approach-2>> Using Recursion + Memoization
         int k =slices.size();
        vector<vector<int>>dp1(k+1, vector<int>((k/3)+1, -1));
        int case1Taken =solveMem(0, k-2, slices, k/3, dp1);
        vector<vector<int>>dp2(k+1, vector<int>((k/3)+1, -1));
        int case2NotTaken =solveMem(1, k-1, slices, k/3, dp2);
        return max(case1Taken, case2NotTaken);
        
        //  // Approach-3>> Using Tabulation
        // return solveTab(slices);
        
         // Approach-4>> Using Space Optimization 
        // return solveSpOpt(slices);
    }
};