class Solution {
public:
    bool solveRec(string s, string p, int i, int j){
        // s and p both end 
        if(i==s.length() && j==p.length()) return true;
        
       bool charMatch = (s[i]==p[j]) || (p[j]=='.');
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
    
    bool isMatch(string s, string p) {
        // // Approach-1: Recursion 
        // return solveRec(s, p, 0, 0);
        
          // Approach-2: Recursion + Memoization
        vector<vector<int>>dp(s.length()+1, vector<int>(p.length()+1, -1));
        return solveMem(s, p, 0, 0, dp);
    }
};