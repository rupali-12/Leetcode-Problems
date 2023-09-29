//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
   int solveRec(int length[], int price[], int n, int index){
         if(index<0 || n==0) return 0;
         
         if(length[index]<=n){
           return max(price[index]+solveRec(length, price, n-length[index], index), solveRec(length, price, n, index-1));
         }
         else{
             return solveRec(length, price, n, index-1);
         }
     }
     int solveMem(int length[], int price[], int n, int index, vector<vector<int>>&dp){
         if(index<0 || n==0) return 0;
         if(dp[index][n]!=-1){
             return dp[index][n];
         }
         
         int notTake =solveMem(length, price, n, index-1, dp);
         int take=0;
         int ans=0;
         if(length[index]<=n){
           take= price[index]+solveMem(length, price, n-length[index], index,dp);
         }
      ans= max(take, notTake);
         return dp[index][n] = ans;
     }
     int solveTab(int length[], int price[], int n){
         vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
         
         for(int i=1; i<=n; i++){
             for(int weight=0; weight<=n; weight++){
                 int ans=0, take=0;
                 int notTake= dp[i-1][weight];
                 if(length[i-1]<=weight){
                     take= price[i-1]+ dp[i][weight-length[i-1]];
                 }
                 ans= max(take, notTake);
                 dp[i][weight]=ans;
             }
         }
         return dp[n][n];
     }
     int solveTabSpOpt(int length[], int price[], int n){
        vector<int>curr(n+1, 0);
        vector<int>prev(n+1, 0);
         
         for(int i=1; i<=n; i++){
             for(int weight=0; weight<=n; weight++){
                 int ans=0, take=0;
                 int notTake= prev[weight];
                 if(length[i-1]<=weight){
                     take= price[i-1]+ curr[weight-length[i-1]];
                 }
                 ans= max(take, notTake);
                 curr[weight]=ans;
             }
             prev=curr;
         }
         return prev[n];
     }
    int cutRod(int price[], int n) {
        //code here
	int length[n];
	for(int i=0; i<n; i++){
		length[i]=i+1;
	}
          // // Approach -1: Recursion 
        // return solveRec(length, price, n, n-1);
        
        //  // Approach -2: Recursion + Memoization
        //  vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // return solveMem(length, price, n, n-1, dp);
        
        //   // Approach -3:Tabulation
        // return solveTab(length, price, n);
        
          // Approach -4:space optimization 
        return solveTabSpOpt(length, price, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends