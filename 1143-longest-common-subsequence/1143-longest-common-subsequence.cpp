class Solution {
public:
    int solveRec(string text1, string text2, int i, int j){
      if(i==text1.length() || j==text2.length()) return 0;
        
        if(text1[i]==text2[j]) return 1 + solveRec(text1, text2, i+1, j+1);
        else{
            return max(solveRec(text1, text2, i+1, j), solveRec(text1, text2, i, j+1));
        }
    }
    int solveMem(string text1, string text2, int i, int j, vector<vector<int>>&dp){
        if(i==text1.length() || j==text2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(text1[i]==text2[j]){
            ans= 1+solveMem(text1, text2, i+1, j+1, dp);
        }
        else{
            ans= max(solveMem(text1, text2, i+1, j, dp), solveMem(text1, text2, i, j+1, dp));
        }
        return dp[i][j]=ans;
    }
    int solveTab(string text1, string text2){
         vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1, 0));
        int ans=0;
         for(int i= text1.length()-1; i>=0; i--){
             for(int j= text2.length()-1; j>=0; j--){
                 if(text1[i]==text2[j]){
                     ans = 1 + dp[i+1][j+1];
                 }
                 else{
                     ans= max(dp[i+1][j], dp[i][j+1]);
                 }
                 dp[i][j]=ans;
             }
         }
        return dp[0][0];
    }
//     int solveSpOpt(string text1, string text2){
       
//     }
    int longestCommonSubsequence(string text1, string text2) {
        // // // Approach-1> Using Recursion
        // return solveRec(text1, text2, 0, 0);

        // // // Approach-2> Using Recursion + Meemoization
        // vector<vector<int>>dp(text1.length(), vector<int>(text2.length(), -1));
        // return solveMem(text1, text2, 0, 0, dp);
       

        //  // Approach-3> Using Tabulation(Bottom up)
        return solveTab(text1, text2);

           // Approach-4> Using Tabulation(Bottom up)+Space optimization
    }
};