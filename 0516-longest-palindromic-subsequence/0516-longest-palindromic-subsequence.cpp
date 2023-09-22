class Solution {
public:
  int solveRec(string s, string revS, int i, int j){
        if(i==s.length() || j==revS.length()){
            return 0;
        }
        if(s[i]==revS[j]){
            return 1+solveRec(s, revS, i+1, j+1);
        }
        else{
            return max(solveRec(s, revS, i+1, j), solveRec(s, revS, i, j+1));
        }
    }
    int solveMem(string s, string revS, int i, int j, vector<vector<int>>&dp){
        if(i==s.length() || j==revS.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==revS[j]){
            ans= 1+solveMem(s, revS, i+1, j+1, dp);
        }
        else{
            ans= max(solveMem(s, revS, i+1, j, dp), solveMem(s, revS, i, j+1, dp));
        }
        return dp[i][j]=ans;
    }
    int solveTab(string s, string revS){
         vector<vector<int>>dp(s.length()+1, vector<int>(revS.length()+1, 0));
         int ans=0;
         for(int i=s.length()-1; i>=0; i--){
             for(int j= revS.length()-1; j>=0; j--){
                 if(s[i]==revS[j]){
                     ans= 1+dp[i+1][j+1];
                 }
                 else{
                     ans= max(dp[i+1][j], dp[i][j+1]);
                 }
                 dp[i][j]=ans;
             }
         }
         return dp[0][0];
    }
    int solveSpOpt(string s, string revS){
        int mx= max(s.length(), revS.length());
        vector<int>curr(revS.length()+1, 0);
        vector<int>next(revS.length()+1, 0);
        // vector<int>curr(mx+1, 0);
        // vector<int>next(mx+1, 0);
         int ans=0;
         for(int i=s.length()-1; i>=0; i--){
             for(int j= revS.length()-1; j>=0; j--){
                 if(s[i]==revS[j]){
                     ans= 1+ next[j+1];
                 }
                 else{
                     ans= max(next[j], curr[j+1]);
                 }
                 curr[j]=ans;
             }
             next= curr;
         }
         return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string revS =s;
         reverse(revS.begin(), revS.end());
        // // Approach-1> Using Recursion
        // return solveRec(s, revS, 0, 0);

        // // Approach-2> Using Recursion + Meemoization
        // vector<vector<int>>dp(s.length()+1, vector<int>(revS.length()+1, -1));
        // return solveMem(s, revS, 0, 0, dp);

        //  // Approach-3> Using Tabulation(Bottom up)
        // return solveTab(s, revS);

           // Approach-4> Using Tabulation(Bottom up)+Space optimization
        return solveSpOpt(s, revS);
    }
};