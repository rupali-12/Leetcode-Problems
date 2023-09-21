//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int solveRec(string s1, string s2, int i, int j){
        if(i==s1.length() || j==s2.length()){
            return 0;
        }
        if(s1[i]==s2[j]){
            return 1+ solveRec(s1, s2, i+1, j+1);
        }
        else{
            return max(solveRec(s1, s2, i+1, j), solveRec(s1, s2, i, j+1));
        }
    }
    int solveMem(string s1, string s2, int i, int j, vector<vector<int>>&dp){
        if(i==s1.length() || j==s2.length()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j]){
            ans= 1+ solveMem(s1, s2, i+1, j+1, dp);
        }
        else{
            ans= max(solveMem(s1, s2, i+1, j, dp), solveMem(s1, s2, i, j+1, dp));
        }
        return dp[i][j]=ans;
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        // // Approach-1: Recursion 
        // int lcs= solveRec(X, Y, 0, 0); 
        // return (m+n - lcs);
        
         // Approach-2: Memoization
         vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        int lcs= solveMem(X, Y, 0, 0, dp); 
        return (m+n - lcs);
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends