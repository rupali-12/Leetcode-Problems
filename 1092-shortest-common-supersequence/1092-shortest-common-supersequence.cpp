class Solution {
public:
    int solveTab(string str1, string str2, vector<vector<int>>&dp, int n,int m){
        int ans=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1]==str2[j-1]){
                    ans= 1 + dp[i-1][j-1];
                }
                else{
                    ans= max(dp[i][j-1], dp[i-1][j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[n][m];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length(), m= str2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        solveTab(str1, str2, dp, n, m);
        string ans="";
        int i=n, j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--; j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans.push_back(str1[i-1]);
                i--;
            }
            else{
                ans.push_back(str2[j-1]);
                j--;
            }
        }
        
        // insert remaining characters  if exist
        while(i>0){
               ans.push_back(str1[i-1]);
                i--;
        }
        while(j>0){
              ans.push_back(str2[j-1]);
                j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};