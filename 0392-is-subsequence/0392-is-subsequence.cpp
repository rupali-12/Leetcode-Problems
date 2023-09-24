class Solution {
public:
    int solve(int i, int j, string s, string t, vector<vector<int>>&dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]= 1+ solve(i-1, j-1, s, t, dp);
        }
        return dp[i][j]= solve(i, j-1, s, t, dp);
    }
    int solveTab(string s, string t, int n){
         vector<vector<int>>dp(s.length()+1, vector<int>(n+1, 0));
        int ans=0;
        for(int i=1; i<=s.length(); i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==t[j-1]){
                    ans= 1 + dp[i-1][j-1];
                }
                else{
                    ans= max(dp[i][j-1], dp[i-1][j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[s.length()][n];
    }
    bool isSubsequence(string s, string t) {
        int n= t.length();
        if(s.length()==0){
            return true;
        }
        
        // // Approach-1: Memoization 
         // vector<vector<int>>dp(s.length(), vector<int>(n+1, -1));
        // int lcsLength= solve(s.length()-1, n-1, s, t, dp);
        
        // Approach-2: Tabulation 
        int lcsLength =solveTab(s, t, n);
        
        if(lcsLength==s.length()){
            return true;
        }
        return false;
    }
};