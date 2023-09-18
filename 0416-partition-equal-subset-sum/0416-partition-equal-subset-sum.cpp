class Solution {
public:
    bool solveRec(int index, vector<int>& nums, int n, int target){
        if(index==n || target<0) return 0;
        if(target==0) return 1;
        
        bool include =  solveRec(index+1, nums, n, target-nums[index]);
        bool exclude =solveRec(index+1, nums, n, target);
        
        // if any one outof two cases then return true; 
        return include || exclude;
    }
     bool solveMem(int index, vector<int>& nums, int n, int target, vector<vector<int>>&dp){
        if(index==n || target<0) return 0;
        if(target==0) return 1;
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        bool include =  solveMem(index+1, nums, n, target-nums[index], dp);
        bool exclude =solveMem(index+1, nums, n, target, dp);
        
        // if any one outof two cases then return true; 
        return dp[index][target] = (include || exclude);
    }
     bool solveTab(vector<int>&nums, int n, int target){
        vector<vector<int>>dp(n+1, vector<int>(target+1, 0));
        for(int i=0; i<n;i++){
            dp[i][0]=1;
        }
        for(int index=n-1; index>=0; index--){
            for(int t=1; t<=target; t++){
                
                bool inc=false;
               if(t-nums[index]>=0){
                   inc = dp[index+1][t-nums[index]];
               }
                bool exc = dp[index+1][t];
                dp[index][t] = inc | exc;
            }
        }
        return dp[0][target];
    }
      bool solveTabSpOpt(vector<int>&nums, int n, int target){
       vector<int>curr(target+1, 0);
       vector<int>next(target+1, 0);
       curr[0]= next[0]=1;
        for(int index=n-1; index>=0; index--){
            for(int t=1; t<=target; t++){
                
                bool inc=false;
               if(t-nums[index]>=0){
                   inc =next[t-nums[index]];
               }
                bool exc = next[t];
                curr[t] = inc || exc;
            }
            next= curr;
        }
        return next[target];
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
         total+= nums[i];   
        }
        if(total%2!=0){
            return false;
        }
        int target= total/2;
        
        // // Approach-1: Recursion 
        // return solveRec(0, nums, n, target);
        
        //  // Approach-2: Recursion + Memoization
        // vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        // return solveMem(0, nums, n, target, dp);
        
        //   // Approach-3:Tabulation
        // return solveTab(nums, n, target);
        
           // Approach-4:Tabulation + space optimization
        return solveTabSpOpt(nums, n, target);
    }
};