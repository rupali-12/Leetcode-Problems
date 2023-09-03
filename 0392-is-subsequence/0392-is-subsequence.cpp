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
    bool isSubsequence(string s, string t) {
        int n= t.length();
        vector<vector<int>>dp(s.length(), vector<int>(n+1, -1));
        if(s.length()==0){
            return true;
        }
        int lcsLength= solve(s.length()-1, n-1, s, t, dp);
        if(lcsLength==s.length()){
            return true;
        }
        return false;
    }
};