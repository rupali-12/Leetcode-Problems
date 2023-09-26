class Solution {
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
        // return solveRec(nums, n-1, target);
        
        //  // Approach-2: Recursion + Memoization
        // vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        // return solveMem(nums, n-1, target, dp);
        
        //   // Approach-3:Tabulation
        // return solveTab(nums, n, target);
        
           // Approach-4:Tabulation + space optimization
        return solveTabSpOpt(nums, n, target);
    }
};