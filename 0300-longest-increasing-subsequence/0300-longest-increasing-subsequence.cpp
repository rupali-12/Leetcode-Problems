class Solution {
public:
    int solveRec(vector<int>nums, int prev, int curr){
        if(curr==nums.size()){
            return 0;
        }
          int ans=0;
            int take= 1+solveRec(nums, curr, curr+1);
            int nottake= solveRec(nums, prev, curr+1);
           if(prev==-1 || nums[curr]>nums[prev]){
            ans=max(take, nottake);
        }
           else{
            ans=nottake;
        }
        return ans;
    }
    
    int solveMem(vector<int>nums, int prev, int curr,  vector<vector<int>>&dp){
        if(curr==nums.size()){
            return 0;
        }
        if(dp[prev+1][curr]!=-1){
            return dp[prev+1][curr];
        }
          int ans=0;
            int take= 1+solveMem(nums, curr, curr+1, dp);
            int nottake= solveMem(nums, prev, curr+1, dp);
           if(prev==-1 || nums[curr]>nums[prev]){
            ans=max(take, nottake);
        }
           else{
            ans=nottake;
        }
        return dp[prev+1][curr] =ans;
    }
    int solveTab(vector<int>nums){
        int n= nums.size();
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
    int lengthOfLIS(vector<int>& nums) {
        // // Approach-1: Recursion 
        // return solveRec(nums, -1, 0, dp);
        
        // // // Approach-2: Memoization 
        // vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size(), -1));
        // return solveMem(nums, -1, 0, dp);
        
        // Approach-3: Tabulation 
        return solveTab(nums);
    }
};

