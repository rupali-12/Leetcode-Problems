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
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n= str1.length(), m= str2.length();
	   // approach-2:Memoization 
	   vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
	   int lcs =  solveMem(str1, str2, 0, 0, dp);
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