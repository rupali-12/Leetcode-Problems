//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solveRec(int* arr, int prev, int curr, int n){
	if(curr==n) return 0;

	int take=0;
	int ans=0;
	if(prev==-1 || arr[curr]>arr[prev]){
       take= arr[curr] + solveRec(arr, curr, curr+1, n);
	   
	}
	int notTake= solveRec(arr, prev, curr+1,  n);
	ans= max(take, notTake);
	return ans;
}
int solveMem(int* arr, int prev, int curr, int n, vector<vector<int>>&dp){
	if(curr==n) return 0;
   if(dp[prev+1][curr]!=-1){
	   return dp[prev+1][curr];
   }
	int take=0;
	int ans=0;
	if(prev==-1 || arr[curr]>arr[prev]){
       take= arr[curr] + solveMem(arr, curr, curr+1, n, dp);
	   
	}
	int notTake= solveMem(arr, prev, curr+1,  n, dp);
	ans= max(take, notTake);
	return dp[prev+1][curr]=ans;
}
int solveTab(int* arr, int n){
	vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
	for(int curr= n-1; curr>=0; curr--){
		for(int prev= curr-1; prev>=-1;  prev--){
		int take=0;
	    int ans=0;
	    if(prev==-1 || arr[curr]>arr[prev]){
          take= arr[curr] + dp[curr+1][curr+1];   // prev= curr and we take prev as prev+1 so prev= curr+1 
	}
	int notTake=dp[prev+1][curr+1];
	ans= max(take, notTake);
	dp[prev+1][curr] = ans;
		}
	}
	return dp[0][0];
}
int solveTabSpOpt(int*arr, int n){
	vector<int>present(n+1, 0);
	vector<int>next(n+1, 0);
	for(int curr= n-1; curr>=0; curr--){
		for(int prev= curr-1; prev>=-1;  prev--){
		int take=0;
	    int ans=0;
	    if(prev==-1 || arr[curr]>arr[prev]){
          take= arr[curr] + next[curr+1];   // prev= curr and we take prev as prev+1 so prev= curr+1 
	}
	int notTake=next[prev+1];
	ans= max(take, notTake);
	present[prev+1] = ans;
		}
		next= present;
	}
	return next[0];
}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    // Approach-1: Recursion 
// 	return solveRec(arr, -1, 0, n);

	// // Approach-2: Recursion + Memoization 
// 	vector<vector<int>>dp(n+1, vector<int>(n, -1));
     return solveMem(arr, -1, 0, n, dp);

	// // Approach-3: Tabulation 
// 	return solveTab(arr, n);

	// Approach-4: Tabulation + space optimization 
// 	return solveTabSpOpt(arr, n);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends