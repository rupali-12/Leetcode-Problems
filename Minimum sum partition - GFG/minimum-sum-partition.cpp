//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
   bool solveTab(int arr[], int n, int sum, vector<vector<bool>>&dp){
      for(int i=0;i<n; i++){
          dp[i][0]=true;
      }
      
      if(arr[0]<=sum) dp[0][arr[0]]=true;
     
      for(int index=1; index<n; index++){
          for(int s= 1; s<=sum/2; s++){
    bool notTake= dp[index-1][s];
      bool take= false;
      if(arr[index]<=s){
          take= dp[index-1][s-arr[index]];
      }
      dp[index][s]=take | notTake;
          }
      }
	  return dp[n][sum];
        
  }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	  int totalSum=0;
	    for(int i=0; i<n; i++){
	        totalSum+=arr[i];
	    }
	    
	   // Approach-1: Memoization
	   vector<vector<bool>>dp(n+1, vector<bool>(totalSum+1, 0));
	   solveTab(arr, n, totalSum, dp);
	    
	    
	   //check valid partitions 
	   int s1, s2, diff=1e9;
	   for(int s1=0; s1<=totalSum/2; s1++){
	       if(dp[n-1][s1]==true){
	           s2= totalSum-s1;
	           diff= min(diff, abs(s2-s1));
	       }
	   }
	   return diff;
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends