class Solution {
public:
    bool solveRec(vector<int>nums, int index, int target){
        if(target==0) return true;
        if(index==0) return nums[index]==target;
        
        bool notTake= solveRec(nums, index-1, target);
        bool take= false;
        if(nums[index]<= target){
            take= solveRec(nums, index-1, target-nums[index]);
        }
        return take | notTake;
    }
    bool solveMem(vector<int>&nums, int index, int target,vector<vector<int>>&dp){
        if(target==0) return true;
        if(index==0) return nums[index]==target;
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        
        bool notTake= solveMem(nums, index-1, target, dp);
        bool take= false;
        if(nums[index]<= target){
            take= solveMem(nums, index-1, target-nums[index], dp);
        }
        return dp[index][target]= take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int total=0;
        for(int i=0; i<n; i++){
            total+= nums[i];
        }
        
        if(total%2!=0) return false;
        int target = total/2;
        
        // // Approach -1: Recursion
        // return solveRec(nums, n-1, target);
        
         // Approach -2: Recursion + Memoization
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return solveMem(nums, n-1, target, dp);
    }
};