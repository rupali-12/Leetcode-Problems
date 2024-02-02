class Solution {
public:
    bool solveRec(string s, string p, int i, int j){
        // s and p both end 
        if(i==s.length() && j==p.length()) return true;
        
       bool charMatch = (i<s.length()) && ((s[i]==p[j]) || (p[j]=='.'));
        bool isNextStar = (j+1<p.length()) && p[j+1]=='*';
        bool isMatch;
        if(charMatch){
            if(isNextStar){
              isMatch =   solveRec(s, p, i, j+2) || solveRec(s, p, i+1, j);
            }
            else{
                isMatch = solveRec(s, p, i+1, j+1);
            }
        }
        else{
            if(isNextStar){
                isMatch = solveRec(s, p, i, j+2);
            }
            else{
                isMatch= false;
            }
        }
        return isMatch;
    }
    
      bool solveMem(string s, string p, int i, int j,vector<vector<int>>&dp){
        // s and p both end 
        if(i==s.length() && j==p.length()) return true;
        
          if(dp[i][j]!=-1){
              return dp[i][j];
          }
       bool charMatch =(i<s.length()) && ((s[i]==p[j]) || (p[j]=='.'));
        bool isNextStar = (j+1<p.length()) && p[j+1]=='*';
        bool isMatch;
        if(charMatch){
            if(isNextStar){
              isMatch =   solveMem(s, p, i, j+2, dp) || solveMem(s, p, i+1, j, dp);
            }
            else{
                isMatch = solveMem(s, p, i+1, j+1, dp);
            }
        }
        else{
            if(isNextStar){
                isMatch = solveMem(s, p, i, j+2, dp);
            }
            else{
                isMatch= false;
            }
        }
        return dp[i][j]= isMatch;
    }
    
    int solveTab(string s, string p){
         vector<vector<int>>dp(s.length()+1, vector<int>(p.length()+1, 0));
        int mr = dp.size()-1;
        int mc = dp[0].size()-1;
        
        for(int i=0; i<=mr; i++){
            for(int j=0; j<=mc; j++){
                if(i==0 && j==0){   // first cell 
                    dp[i][j] = true;
                }
                else if(i==0){    // first row
                    if(p[j-1]=='*'){
                        dp[i][j]=dp[i][j-2];
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
                else if(j==0){   // first column
                    dp[i][j]= false;
                }
                else{
                    if((s[i-1]==p[j-1]) || p[j-1]=='.'){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(p[j-1]=='*'){
                        dp[i][j]= dp[i][j-2];   // case c*-> empty
                        char prev = p[j-2];
                        if(prev=='.' || (prev==s[i-1])){
                            dp[i][j] = dp[i][j] || dp[i-1][j];
                        }
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
            }
        }
        return dp[mr][mc];
    }
    bool isMatch(string s, string p) {
        // // Approach-1: Recursion 
        // return solveRec(s, p, 0, 0);
        
        //   // Approach-2: Recursion + Memoization
        // vector<vector<int>>dp(s.length()+1, vector<int>(p.length()+1, -1));
        // return solveMem(s, p, 0, 0, dp);
        
          // Approach-3: Tabulation 
        return solveTab(s, p);
    }
};