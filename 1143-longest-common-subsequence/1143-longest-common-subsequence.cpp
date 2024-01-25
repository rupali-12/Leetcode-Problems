class Solution {
public:
    int solveRec(string text1, string text2, int i, int j){
        if(i==text1.length() || j==text2.length()) return 0;
        
        if(text1[i]==text2[j]){
            return 1+solveRec(text1, text2, i+1, j+1);
        }
        return max(solveRec(text1, text2, i+1, j), solveRec(text1, text2, i, j+1));
    }
    
     int solveMem(string text1, string text2, int i, int j, vector<vector<int>>&dp){
        if(i==text1.length() || j==text2.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]){
            return dp[i][j]= 1+solveMem(text1, text2, i+1, j+1, dp);
        }
        return dp[i][j]= max(solveMem(text1, text2, i+1, j, dp), solveMem(text1, text2, i, j+1, dp));
    }
    
     int solveTab(string text1, string text2){
          int len1= text1.length(), len2= text2.length();
        vector<vector<int>>dp(len1+1, vector<int>(len2+1, 0));
       for(int i=len1-1; i>=0; i--){
           for(int j=len2-1; j>=0; j--){
        if(text1[i]==text2[j]){
            dp[i][j]= 1+ dp[i+1][j+1];
        }
         else{
             dp[i][j]= max(dp[i+1][j], dp[i][j+1]);
         }
           }
       }  
       return dp[0][0];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
//         // Approach-1: Recursion 
//         return solveRec(text1, text2, 0, 0);
                
        // // Approach-2: Recursion + Memoization
        // vector<vector<int>>dp(len1, vector<int>(len2, -1));
        // return solveMem(text1, text2, 0, 0, dp);
        
        // Approach-3: Tabulation
        return solveTab(text1, text2);
    }
};