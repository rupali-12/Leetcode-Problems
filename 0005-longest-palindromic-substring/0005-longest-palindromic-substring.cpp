class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        int maxLength =INT_MIN;
        vector<vector<int>>dp(n, vector<int>(n, 0));
        
        for(int diff=0; diff<n; diff++){
             for(int i=0, j=i+diff; j<n; i++, j++){
                if(i==j) dp[i][j]=1;
                else if(diff==1){
                    if(s[i]==s[j]) dp[i][j]=1;
                    else dp[i][j]=0;
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]>0){
                        dp[i][j]= dp[i+1][j-1] + 2;
                    }
                }
                // update ans and maxlength 
                if(dp[i][j]){
                    if(j-i+1>maxLength){
                        maxLength= j-i+1;
                        ans= s.substr(i, maxLength);
                    }
                }
            }
        }
        return ans;
    }
};