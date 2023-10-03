class Solution {
public:
    bool solveRec(string s, string p, int i, int j){
        // Base cases 
        if(i<0 && j<0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            for(int k=0; k<=j; k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }

        // case of match
        if((s[i]==p[j]) || (p[j]=='?')){
            return solveRec(s, p, i-1, j-1);
        }
        else if(p[j]=='*'){
// case of replacement by empty string || case of replacement by *character   *->*ch
            return (solveRec(s, p, i-1, j) || solveRec(s, p, i, j-1));
        }
        else{
            return false;
        }
    }
    bool solveMem(string s, string p, int i, int j, vector<vector<int>>&dp){
        // Base cases 
        if(i<0 && j<0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            for(int k=0; k<=j; k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // case of match
        if((s[i]==p[j]) || (p[j]=='?')){
            return dp[i][j]= solveMem(s, p, i-1, j-1, dp);
        }
        else if(p[j]=='*'){
// case of replacement by empty string || case of replacement by *character   *->*ch
            return dp[i][j]= (solveMem(s, p, i-1, j, dp) || solveMem(s, p, i, j-1, dp));
        }
        else{
            return false;
        }
    }
    bool solveMemWith1BasedIndexing(string s, string p, int i, int j, vector<vector<int>>&dp){
        // Base cases 
        if(i==0 && j==0){
            return true;
        }
        if(i>=0 && j==0){
            return false;
        }
        if(i==0 && j>=0){
            for(int k=1; k<=j; k++){
                if(p[k-1]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // case of match
        // as for i=1 we want to accesss data at i=0
        if((s[i-1]==p[j-1]) || (p[j-1]=='?')){
            return dp[i][j]= solveMemWith1BasedIndexing(s, p, i-1, j-1, dp);
        }
        else if(p[j-1]=='*'){
// case of replacement by empty string || case of replacement by *character   *->*ch
            return dp[i][j]= (solveMemWith1BasedIndexing(s, p, i-1, j, dp) || solveMemWith1BasedIndexing(s, p, i, j-1, dp));
        }
        else{
            return false;
        }
    }
    bool solveTab(string s, string p){
        vector<vector<int>>dp(s.length()+1, vector<int>(p.length()+1, 0));
        dp[0][0]=1;
        for(int i=1; i<s.length(); i++){
            dp[i][0]=0;
        }
        for(int j=1; j<=p.length(); j++){
            bool flag=true;
           for(int k=1; k<=j; k++){
                if(p[k-1]!='*'){
               flag=false;
               break;
            }
           }
           dp[0][j]=flag;
        }
        for(int i=1;i<=s.length(); i++){
            for(int j=1; j<=p.length(); j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]= dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]= dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j]= false;
                }
            }
        }
        return dp[s.length()][p.length()];
    }
    bool solveSpOpt(string s, string p){
        vector<int>prev(p.length()+1, 0);
        vector<int>curr(p.length()+1, 0);
         prev[0]=true;
         for(int j=1; j<=p.length(); j++){
             bool flag=true;
             for(int k=1; k<=j; k++){
                 if(p[k-1]!='*'){
                     flag=false;
                     break;
                 }
             }
             prev[j]=flag;
         }
        for(int i=1; i<=s.length(); i++){
            for(int j=1; j<=p.length();j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    curr[j]=prev[j-1];
                }
                else if(p[j-1]=='*'){
                    curr[j]=prev[j] || curr[j-1];
                }
                else{
                    curr[j]=false;
                }
            }
            prev=curr;
        }
        return prev[p.length()];

    }
    bool isMatch(string s, string p) {
        // // Approach-1>> Using Recursion
        // return solveRec(s, p, s.length()-1, p.length()-1);

        // // Approach-2>> Using Recursion + Memoization
        // vector<vector<int>>dp(s.length(), vector<int>(p.length(), -1));
        // return solveMem(s, p, s.length()-1, p.length()-1, dp);
        // vector<vector<int>>dp(s.length()+1, vector<int>(p.length()+1, -1));
        // return solveMemWith1BasedIndexing(s, p, s.length(), p.length(), dp);

    //     // Approach-3>> Using Tabulation
    //    return solveTab(s, p);

        // Approach-4>> Using Tabulation + Space Optimization
       return solveSpOpt(s, p);
    }
};