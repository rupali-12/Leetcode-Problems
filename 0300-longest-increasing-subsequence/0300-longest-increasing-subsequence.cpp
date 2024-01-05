class Solution {
public:
    int solveRec(vector<int>&nums, int prev, int curr){
        if(curr== nums.size()){
            return 0;
        }
        int take = 1 + solveRec(nums, curr, curr+1);
        int notTake= solveRec(nums, prev, curr+1);
        int ans;
        if(prev==-1 || nums[curr]>nums[prev]){
            ans = max(take, notTake);    // if prev==-1 then also we have to choose we take or not 
        }
        else{
            ans= notTake;
        }
        return ans;
    }
      int solveMem(vector<int>&nums, int prev, int curr, vector<vector<int>>&dp){
        if(curr== nums.size()){
            return 0;
        }
          if(dp[curr][prev+1]!=-1){
              return dp[curr][prev+1];
          }
        int take = 1 + solveMem(nums, curr, curr+1, dp);
        int notTake= solveMem(nums, prev, curr+1, dp);
        int ans;
        if(prev==-1 || nums[curr]>nums[prev]){
            ans = max(take, notTake);    // if prev==-1 then also we have to choose we take or not 
        }
        else{
            ans= notTake;
        }
        return dp[curr][prev+1] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        
//         // Approach-1 : Recursion 
//         // (num, prev, curr)
//         return solveRec(nums, -1, 0);
        
        // Approach-2 : Recursion + Memoization
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solveMem(nums, -1, 0, dp);
    }
};