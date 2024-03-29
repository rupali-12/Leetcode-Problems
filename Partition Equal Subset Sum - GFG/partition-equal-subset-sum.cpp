//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool solveRec(int N, int *arr, int i, int target){
    if(i>=N){
        return 0;
    }
    if(target<0){
        return 0;
    }
    if(target==0){
        return 1;
    }
    bool include =  solveRec(N, arr, i+1, target-arr[i]);
    bool exclude =  solveRec(N, arr, i+1, target);
    return include or exclude;
}

bool solveMem(int N, int *arr, int i, int target, vector<vector<int>>&dp){
    if(i>=N || target<0){
        return 0;
    }
    if(target==0){
        return 1;
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    bool include =solveMem(N, arr, i+1, target-arr[i], dp);
    bool exclude= solveMem(N, arr, i+1, target, dp);
    dp[i][target]= include | exclude;
}
int solveTab(int N, int *arr, int target){
     vector<vector<int>>dp(N+1, vector<int>(target+1, 0));
    //  when target=0 
    for(int i=0; i<N; i++){
        dp[i][0]=1;
    }
     for(int i=N-1; i>=0; i--){
         for(int t = 1; t<=target; t++){
             int include=0;
             if(t-arr[i]>=0){
                 include =dp[i+1][t-arr[i]];
             }
             int exclude =dp[i+1][t];
             dp[i][t]=include | exclude;
         }
     }
     return dp[0][target];
}
int solveSpOpt(int N, int *arr, int target){
    vector<int>curr(target+1);
    vector<int>next(target+1);
    curr[0]=1;
    next[0]=1;
    for(int i=N-1; i>=0; i--){
        for(int t=0; t<=target; t++){
            int include=0;
            if(t-arr[i]>=0){
                include = next[t-arr[i]];
            }
            int exclude = next[t];
            curr[t]=include | exclude;
        }
        next=curr;
    }
    return next[target];
}
    int equalPartition(int N, int arr[])
    {
        // code here
        int total=0;
        for(int i=0; i<N; i++){
            total+= arr[i];
        }
        if(total & 1 !=0){   //odd total cannot be partitioned
            return 0;
        }
        int target=total/2;
        
        // // Approach-1>> Using Recursion 
        // return solveRec(N, arr, 0, target);
        
        //  // Approach-2>> Using Recursion + memoization
        //  vector<vector<int>>dp(N+1, vector<int>(target+1, -1));
        // return solveMem(N, arr, 0, target, dp);
        
        //   // Approach-3>> Using Tabulation
        // return solveTab(N, arr, target);
        
        // Approach-4>> Using Space optimization
        return solveSpOpt(N, arr, target);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends