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
    int solveTab(vector<int>&nums, int n){
         vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        
        for(int curr= n-1; curr>=0; curr--){
            for(int prev= curr-1; prev>=-1; prev--){
        int take = 1 + dp[curr+1][curr+1];   // prev= curr+1 bcoz we consider prev=prev+1 due to some prev=-1 so when we do prev = curr it becomes prev = prev+1 = curr+1;
        int notTake= dp[curr+1][prev+1];
        int ans;
        if(prev==-1 || nums[curr]>nums[prev]){
            ans = max(take, notTake);    // if prev==-1 then also we have to choose we take or not 
        }
        else{
            ans= notTake;
            }   
           dp[curr][prev+1] = ans;     
        }
    }
        return dp[0][0];
}
      int solveTabSpOpt(vector<int>&nums, int n){
         vector<int>nextRow(n+1, 0);
        vector<int>currRow(n+1, 0);
        for(int curr= n-1; curr>=0; curr--){
            for(int prev= curr-1; prev>=-1; prev--){
        int take = 1 + nextRow[curr+1];   // prev= curr+1 bcoz we consider prev=prev+1 due to some prev=-1 so when we do prev = curr it becomes prev = prev+1 = curr+1;
        int notTake= nextRow[prev+1];
        int ans;
        if(prev==-1 || nums[curr]>nums[prev]){
            ans = max(take, notTake);    // if prev==-1 then also we have to choose we take or not 
        }
        else{
            ans= notTake;
            }   
          currRow[prev+1] = ans;     
        }
            nextRow= currRow;
    }
        return currRow[0];  // as well nextRow[0];
}
    int optimizedAp(vector<int>&nums, int n){
        if(n==0) return 0;
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n; i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                // find index where value is just greater than nums[i]
                int index = lower_bound( ans.begin(),ans.end(), nums[i])- ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        
//         // Approach-1 : Recursion 
//         // (num, prev, curr)
//         return solveRec(nums, -1, 0);
        
//         // Approach-2 : Recursion + Memoization
//         vector<vector<int>>dp(n, vector<int>(n, -1));
//         return solveMem(nums, -1, 0, dp);
                
//         // Approach-3 : Tabulation
//         return solveTab(nums, n);
                     
//         // Approach-4 : Tabulation + Space Optimization
//         return solveTabSpOpt(nums, n);
                      
        // Approach-5 : Optimized Approach
        return optimizedAp(nums, n);
    }
};