//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
  bool solveRec(vector<int>&arr, int index, int sum){
      if(sum==0) return true;
      if(index==0) return arr[index]==sum;

      bool notTake =solveRec(arr, index-1, sum);
      bool take= false;
      if(arr[index]<=sum){
          take = solveRec(arr, index-1, sum-arr[index]);
      }
      return take | notTake;
   }
   bool solveMem(vector<int>&arr, int index, int sum, vector<vector<int>>&dp){
      if(sum==0) return true;
      if(index==0) return arr[index]==sum;
   if(dp[index][sum]!=-1){
       return dp[index][sum];
   }
      bool notTake =solveMem(arr, index-1, sum, dp);
      bool take= false;
      if(arr[index]<=sum){
          take = solveMem(arr, index-1, sum-arr[index], dp);
      }
      return dp[index][sum] =  take | notTake;
   }
   bool solveTab(vector<int>&arr, int sum, int n){
        vector<vector<int>>dp(arr.size()+1, vector<int>(sum+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0]=true;
        }
     for(int index=1; index<=n; index++){
         for(int s=1; s<=sum; s++){
             bool ans=false;
             if(arr[index-1]<=s){
                  bool include= dp[index-1][s-arr[index-1]];
                  bool exclude= dp[index-1][s];
                  ans= include || exclude;
             }
             else{
                 ans= dp[index-1][s];
             }
             dp[index][s]= ans;
         }
     }
        
      return dp[n][sum];
   }
   bool solveTabSpOpt(vector<int>&arr, int sum, int n){
        vector<int>prev(sum+1, 0);
        vector<int>curr(sum+1, 0);
        
       prev[0]=true;
       curr[0]=true;
       
     for(int index=1; index<=n; index++){
         for(int s=1; s<=sum; s++){
             bool ans=false;
             if(arr[index-1]<=s){
                  bool include= prev[s-arr[index-1]];
                  bool exclude= prev[s];
                  ans= include || exclude;
             }
             else{
                 ans= prev[s];
             }
             curr[s]= ans;
         }
         prev=curr;
     }
        
      return prev[sum];
   }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        
        // // Approach-1: Recursion
        // return solveRec(arr, arr.size()-1, sum);
        
        // // Approach-2: Memoization
        vector<vector<int>>dp(arr.size()+1, vector<int>(sum+1, -1));
        return solveMem(arr, arr.size()-1, sum, dp);
        
        //   // Approach-3: Tabulation
        //   int n= arr.size();
        // return solveTab(arr, sum, n);
        
        //   // Approach-4: Space optimization
        //   int n= arr.size();
        // return solveTabSpOpt(arr, sum, n);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends