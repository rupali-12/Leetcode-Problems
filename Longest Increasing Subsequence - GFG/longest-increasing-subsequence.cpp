//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
     int solveRec(int nums[],int n, int prev, int curr){
        if(curr==n){
            return 0;
        }
          int ans=0;
            int take= 1+solveRec(nums,n, curr, curr+1);
            int nottake= solveRec(nums,n, prev, curr+1);
           if(prev==-1 || nums[curr]>nums[prev]){
            ans=max(take, nottake);
        }
           else{
            ans=nottake;
        }
        return ans;
    }
    
    int solveMem(int nums[], int n, int prev, int curr,  vector<vector<int>>&dp){
        if(curr==n){
            return 0;
        }
        if(dp[prev+1][curr]!=-1){
            return dp[prev+1][curr];
        }
          int ans=0;
            int take= 1+solveMem(nums,n, curr, curr+1, dp);
            int nottake= solveMem(nums,n, prev, curr+1, dp);
           if(prev==-1 || nums[curr]>nums[prev]){
            ans=max(take, nottake);
        }
           else{
            ans=nottake;
        }
        return dp[prev+1][curr] =ans;
    }
    int solveTab(int nums[],int n){
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
         for(int curr=n-1; curr>=0; curr--){
        for(int prev=curr-1; prev>=-1; prev--){
            
            // include
            int take=0;
                if(prev==-1 || nums[curr]>nums[prev]){
                   take=1+ dp[curr+1][curr+1];  // its prev but we consider prev as prev+1
                }
            
            //Exclude
            int nottake= 0+dp[curr+1][prev+1];  // as prev also equal to -1 for some cases 
         dp[curr][prev+1] = max(take, nottake);
            }
        }
        return dp[0][0];
    }
        int solveSpOpt(int nums[],int n){
       vector<int>nextRow(n+1, 0);
             vector<int>currentRow(n+1, 0);
         for(int curr=n-1; curr>=0; curr--){
        for(int prev=curr-1; prev>=-1; prev--){
            
            // include
            int take=0;
                if(prev==-1 || nums[curr]>nums[prev]){
                   take=1+nextRow [curr+1];  // its prev but we consider prev as prev+1
                }
            
            //Exclude
            int nottake= 0+ nextRow[prev+1];  // as prev also equal to -1 for some cases 
         currentRow[prev+1] = max(take, nottake);
            }
             nextRow= currentRow;
        }
        return nextRow[0];
    }
        // optimized 
    int optimizedSol(int nums[], int n){
        if(n==0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=0; i<n; i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                // find the index which is just recent larger than a[i]
                int index = lower_bound(ans.begin(), ans.end(), nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
         // // Approach-1: Recursion 
        // return solveRec(a, n, -1, 0);
        
        // // // Approach-2: Memoization 
        // vector<vector<int>>dp(n+1, vector<int>(n, -1));
        // return solveMem(a,n, -1, 0, dp);
        
        // // Approach-3: Tabulation 
        // return solveTab(a, n);
        
        //  // Approach-4: Tabulation + space optimization
        // return solveSpOpt(a, n);
        
              // Approach-5: Optimized Approach 
        return optimizedSol(a, n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends