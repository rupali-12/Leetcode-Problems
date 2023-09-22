//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solveMem(string str1, string str2, int i, int j, vector<vector<int>>&dp){
	    if(i==str1.length() || j==str2.length()) return 0;
	     if(dp[i][j]!=-1){
	         return dp[i][j];
	     }
	    int ans=0;
	    if(str1[i]==str2[j]){
	       ans = 1 + solveMem(str1, str2, i+1, j+1, dp); 
	    }
	    else{
	     ans=max(solveMem(str1, str2, i+1, j, dp), solveMem(str1, str2, i, j+1, dp));   
	    }
	    return dp[i][j]=ans;
	}
	int solveTab(string str1, string str2, int n, int m){
	    vector<vector<int>>dp(n+1, vector<int>(m+1, -0));
	   
	   for(int i=1; i<=n; i++){
	       for(int j=1; j<=m; j++){
	    int ans=0;
	    if(str1[i-1]==str2[j-1]){
	       ans = 1 + dp[i-1][j-1]; 
	    }
	    else{
	     ans=max(dp[i-1][j], dp[i][j-1]);   
	    }
	    dp[i][j]=ans;
	       }
	   }
	    return dp[n][m];
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n= str1.length(), m= str2.length();
	    
	   //// approach-2:Memoization 
	   //vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
	   //int lcs =  solveMem(str1, str2, 0, 0, dp);
	   
	   //Approach-2: Tabulation 
	   int lcs= solveTab(str1, str2, n, m);
	   
	    int numOfDeletions = str1.length() - lcs;
	    int numOfInsertions = str2.length() - lcs;
	    int ans= numOfDeletions + numOfInsertions;
	    return ans;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends