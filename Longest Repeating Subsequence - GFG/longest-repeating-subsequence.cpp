//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int solveMem(int i, int j, string &s, string &text, vector<vector<int>>&dp){
	    if(i<0 || j<0){
	        return 0;
	    }
	    if(dp[i][j]!=-1){
	        return dp[i][j];
	    }
	    if(s[i]==text[j] && i!=j){
	      return dp[i][j]= 1 + solveMem(i-1, j-1, s, text, dp);
	    }
	  return dp[i][j]=  max(solveMem(i-1, j, s, text, dp) , solveMem(i, j-1, s, text, dp));
	}
	int solveTab(string s, string text, int n){
	    int ans=0;
	    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
	    for(int i=1; i<=n ;i++){
	        for(int j=1; j<=n; j++){
	            if(s[i-1]==text[j-1] && i!=j){
	             ans= 1 + dp[i-1][j-1];   
	            }
	            else{
	                ans= max(dp[i-1][j], dp[i][j-1]);
	            }
	            dp[i][j]=ans;
	        }
	    }
	    return dp[n][n];
	}
  
		int LongestRepeatingSubsequence(string s){
		    // Code here
		    int n= s.length();
		    string text=s;
		
      // // Approach-1 Memoization 
        // vector<vector<int>>dp(n, vector<int>(n, -1));
       //  return solve(n-1, n-1, s, text, dp);

          // Approach-2: Tabulation 
          return solveTab(s, text, n);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends