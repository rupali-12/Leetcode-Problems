//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int solveRec(int n){
	    if(n==0) return 0;
	    int ans = n;   // n can be max ans if i make number by 1 only 
	    for(int i=1; i*i<=n; i++){
	        ans= min(ans, 1 + solveRec(n-i*i));
	    }
	    return ans;
	}
	int solveMem(int n, vector<int>&dp){
	     if(n==0) return 0;
	     if(dp[n]!=-1){
	         return dp[n];
	     }
	    int ans = n;   // n can be max ans if i make number by 1 only 
	    for(int i=1; i*i<=n; i++){
	        ans= min(ans, 1 + solveMem(n-i*i, dp));
	    }
	    return dp[n]=ans;
	}
	int solveTab(int n){
	    vector<int>dp(n+1, 0);
	    for(int x=1; x<=n; x++){
	        int ans=x;
	        for(int i=1; i*i<=x; i++){
	            ans= min(ans, 1+dp[x-i*i]);
	        }
	        dp[x]=ans;
	    }
	    return dp[n];
	}
	int MinSquares(int n)
	{
	    // Code here
	    
	   // // Approach-1: Recursion 
	   // return solveRec(n);
	   
	   // // Approach-2: Memoization 
	   //vector<int>dp(n+1, -1);
	   // return solveMem(n, dp);
	   
	   //Approach-3: Tabulation 
	   return solveTab(n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends